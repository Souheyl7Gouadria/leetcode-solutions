select activity_date as day, count(distinct(user_id)) as active_users 
from Activity
where activity_type in ('open_session','end_session','scroll_down','send_message')
and activity_date BETWEEN '2019-06-28' AND '2019-07-27'
group by activity_date;