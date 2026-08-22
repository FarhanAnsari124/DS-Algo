# Write your MySQL query statement below
-- SELECT *
-- FROM Cinema c2
-- WHERE c2.id NOT IN
-- WITH cte AS
-- (
SELECT *
FROM Cinema c
WHERE c.id%2<>0 AND c.description<>'boring'
-- )
-- SELECT *
-- FROM Cinema c2
-- WHERE c2.id NOT IN (SELECT id FROM cte)
ORDER BY rating DESC