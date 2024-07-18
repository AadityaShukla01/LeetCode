# Write your MySQL query statement below
-- CORELATED SUBQUERY

SELECT IFNULL((SELECT DISTINCT e1.salary FROM 
Employee e1
WHERE 1 = (
    SELECT COUNT(DISTINCT e2.salary) FROM Employee e2
    WHERE e2.salary > e1.salary
)), NULL) AS SecondHighestSalary;