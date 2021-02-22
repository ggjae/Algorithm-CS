-- 코드를 입력하세요
SELECT animal_id, name
from animal_ins a 
where a.datetime > (select datetime from animal_outs b where b.animal_id = a.animal_id)
order by a.datetime

# select a.name, a.datetime, b.datetime, b.name
# from animal_ins a, animal_outs b
# where a.animal_id = b.animal_id
# and a.datetime > b.datetime
# order by 2,3