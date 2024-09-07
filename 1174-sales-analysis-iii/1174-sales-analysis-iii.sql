# Write your MySQL query statement below
SELECT p.product_id, p.product_name FROM Product p
JOIN Sales s 
ON p.product_id = s.product_id
GROUP BY product_id
HAVING MAX(sale_date) BETWEEN "2019-01-01" AND "2019-03-31"
AND MIN(sale_date) BETWEEN "2019-01-01" AND "2019-03-31";