# Write your MySQL query statement below
SELECT
    email As Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;