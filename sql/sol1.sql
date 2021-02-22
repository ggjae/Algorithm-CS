# select a.animal_id, a.name
# from animal_is a
# where not exists ( select 1 from animal_ins b where b.animal_id = a.animal_id)
# -- 코드를 입력하세요
# SELECT a.animal_id, a.name
# from animal_ins a left outer join animal_outs b
# on a.animal_id = b.animal_id
# order by 1,2
# -- out나간애들있고 in들어온애 없음
select a.animal_id, a.name
from animal_outs a
where a.animal_id not in (select b.animal_id from animal_ins b)