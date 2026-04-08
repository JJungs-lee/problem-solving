-- # Write your MySQL query statement below
SELECT
    w1.id
FROM Weather AS w1, Weather AS w2
WHERE
    DATE_ADD(w2.recordDate, INTERVAL 1 DAY) = w1.recordDate
    AND w1.temperature > w2. temperature