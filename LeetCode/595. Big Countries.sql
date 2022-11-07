# Write your MySQL query statement below
SELECT 
    name, population, area
FROM 
    World
WHERE 1=1
    AND (population >= 25000000 OR area >= 3000000)