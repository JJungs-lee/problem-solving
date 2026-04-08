# Write your MySQL query statement below
SELECT p.product_id, p.product_name
FROM Product AS p, Sales AS s
WHERE p.product_id = s.product_id 
GROUP BY s.product_id 
HAVING MIN(sale_date) >= "2019-01-01" AND MAX(sale_date) <= "2019-03-31"