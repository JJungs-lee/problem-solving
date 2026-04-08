# Write your MySQL query statement below
SELECT
    p.firstName, p.lastName, s.city, s.state
FROM Person AS p
LEFT JOIN Address AS s ON p.personID = s.PersonID