-- Last updated: 7/6/2026, 12:08:46 PM
# Write your MySQL query statement below
select  e.name,b.bonus from Employee e LEFT JOIN Bonus b on e.empId=b.empId where bonus <1000 or b.empId is null