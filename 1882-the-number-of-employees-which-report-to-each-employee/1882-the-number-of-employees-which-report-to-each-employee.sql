# Write your MySQL query statement below
SELECT reports_to AS employee_id, (SELECT name FROM Employees e1 WHERE 
e1.employee_id = e2.reports_to) AS name, COUNT(*) AS reports_count, ROUND(AVG(age)) AS average_age FROM Employees e2 WHERE reports_to IS NOT NULL GROUP BY reports_to ORDER BY employee_id;