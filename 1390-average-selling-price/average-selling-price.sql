# Write your MySQL query statement below
WITH cte AS
(SELECT p.product_id,u.units,p.price*u.units AS amnt
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
WHERE u.purchase_date>=p.start_date AND p.end_date>=u.purchase_date OR purchase_date IS NULL)

SELECT product_id,CASE WHEN ROUND(SUM(amnt)/SUM(units),2) IS NOT NULL THEN ROUND(SUM(amnt)/SUM(units),2) ELSE 0 END AS average_price
FROM cte
GROUP BY product_id
ORDER BY product_id
