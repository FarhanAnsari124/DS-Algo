# Write your MySQL query statement below
SELECT p.product_id,CASE WHEN ROUND(SUM(price*units)/SUM(units),2) IS NOT NULL THEN ROUND(SUM(price*units)/SUM(units),2) ELSE 0 END AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
WHERE (u.purchase_date BETWEEN p.start_date AND p.end_date) OR u.purchase_date IS NULL
GROUP BY product_id
ORDER BY product_id
