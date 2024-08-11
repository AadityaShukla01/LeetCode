# Write your MySQL query statement below
SELECT d.name AS Department, e1.name AS Employee, Salary
FROM Employee e1 JOIN Department d
ON e1.departmentId = d.id
WHERE 1 = (
    SELECT COUNT(DISTINCT e2.Salary) FROM Employee e2 WHERE
    e2.salary >= e1.salary AND e2.departmentId = e1.departmentId
);