# Write your MySQL query statement below
SELECT id, COUNT(*) as num 
FROM
(SELECT requester_id as id FROM RequestAccepted

UNION ALL

SELECT accepter_id FROM RequestAccepted) AS temp
GROUP BY id 
ORDER BY num DESC 
LIMIT 1;