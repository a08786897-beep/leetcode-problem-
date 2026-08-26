# Write your MySQL query statement below
DELETE p1
FROM Person P1
JOIN Person P2
    ON p1.email=p2.email
WHERE p1.id>p2.id;