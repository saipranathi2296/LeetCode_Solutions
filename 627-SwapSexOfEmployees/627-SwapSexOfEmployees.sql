-- Last updated: 7/6/2026, 12:08:43 PM
UPDATE Salary
set sex=
CASE
when sex='m' then 'f'
ELSE 'm'
END;