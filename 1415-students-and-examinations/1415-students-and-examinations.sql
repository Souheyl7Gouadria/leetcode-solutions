# Write your MySQL query statement below
SELECT s.student_id , s.student_name , sub.subject_name , count(exam.subject_name) as attended_exams
FROM Students s 
JOIN subjects sub
LEFT JOIN Examinations exam
ON s.student_id = exam.student_id AND exam.subject_name = sub.subject_name
GROUP BY s.student_id,sub.subject_name
ORDER BY s.student_id,sub.subject_name;