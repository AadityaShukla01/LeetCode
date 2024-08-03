# Write your MySQL query statement below
SELECT employee_id FROM Employees WHERE manager_id
NOT IN (SELECT e1.employee_id FROM Employees e1 JOIN Employees e2
ON
e1.employee_id = e2.manager_id) AND salary < 30000 ORDER BY employee_id;