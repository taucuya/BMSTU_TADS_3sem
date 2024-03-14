import re as re

filename = input("Введите имя файла: ")

file = open(filename, 'w')

result = "School is an institution where students go to receive formal education. It plays a crucial role in shaping the future of individuals and society as a whole. The school provides a platform for students to learn various subjects, develop skills, and gain knowledge that will help them succeed in life.A typical school day starts early in the morning when students arrive at the school premises. They gather in their respective classrooms and are greeted by their teachers. The classrooms are equipped with desks, chairs, and a blackboard where teachers write important information and lessons.The school curriculum includes a wide range of subjects such as mathematics, science, social studies, language arts, physical education, and more. Each subject is taught by specialized teachers who have expertise in their respective fields. The teachers use various teaching methods and techniques to make the learning process interesting and engaging for the students.Apart from academic subjects, schools also focus on extracurricular activities. These activities include sports, music, dance, drama, art, and various clubs and organizations. Extracurricular activities help students explore their interests and talents outside the classroom. They also promote teamwork, leadership skills, and overall personality development.Schools also have libraries where students can access a wide range of books, magazines, and reference materials. The library is a quiet place where students can study, do research, or simply enjoy reading. It is a valuable resource for students to expand their knowledge and enhance their reading skills.In addition to classrooms and libraries, schools also have laboratories for practical subjects like science and computer studies. These labs are equipped with necessary equipment and tools for conducting experiments and hands-on learning. Practical sessions in labs help students understand the theoretical concepts better and apply them in real-life situations.Schools also organize field trips and educational tours to enhance the learning experience. These trips allow students to explore new places, learn about different cultures, and gain practical knowledge outside the classroom environment. Field trips provide a break from routine studies and make learning more enjoyable and memorable.Schools also play a crucial role in promoting discipline and good behavior among students. They have a set of rules and regulations that students are expected to follow. These rules teach students the importance of punctuality, respect for others, and responsibility. Schools often have a disciplinary committee that handles any misconduct or disciplinary issues.Moreover, schools provide a safe and secure environment for students. They have security measures in place to ensure the safety of students within the school premises. Schools also have counselors and psychologists who provide guidance and support to students facing personal or emotional challenges.In conclusion, schools are essential institutions that provide education, skills, and knowledge to students. They offer a wide range of subjects, extracurricular activities, libraries, labs, and field trips to enhance the learning experience. Schools also promote discipline, good behavior, and provide a safe environment for students to grow and develop."
result += "School is an institution where students go to receive formal education. It plays a crucial role in shaping the future of individuals and society as a whole. The school provides a platform for students to learn various subjects, develop skills, and gain knowledge that will help them succeed in life.A typical school day starts early in the morning when students arrive at the school premises. They gather in their respective classrooms and are greeted by their teachers. The classrooms are equipped with desks, chairs, and a blackboard where teachers write important information and lessons.The school curriculum includes a wide range of subjects such as mathematics, science, social studies, language arts, physical education, and more. Each subject is taught by specialized teachers who have expertise in their respective fields. The teachers use various teaching methods and techniques to make the learning process interesting and engaging for the students.Apart from academic subjects, schools also focus on extracurricular activities. These activities include sports, music, dance, drama, art, and various clubs and organizations. Extracurricular activities help students explore their interests and talents outside the classroom. They also promote teamwork, leadership skills, and overall personality development.Schools also have libraries where students can access a wide range of books, magazines, and reference materials. The library is a quiet place where students can study, do research, or simply enjoy reading. It is a valuable resource for students to expand their knowledge and enhance their reading skills.In addition to classrooms and libraries, schools also have laboratories for practical subjects like science and computer studies. These labs are equipped with necessary equipment and tools for conducting experiments and hands-on learning. Practical sessions in labs help students understand the theoretical concepts better and apply them in real-life situations.Schools also organize field trips and educational tours to enhance the learning experience. These trips allow students to explore new places, learn about different cultures, and gain practical knowledge outside the classroom environment. Field trips provide a break from routine studies and make learning more enjoyable and memorable.Schools also play a crucial role in promoting discipline and good behavior among students. They have a set of rules and regulations that students are expected to follow. These rules teach students the importance of punctuality, respect for others, and responsibility. Schools often have a disciplinary committee that handles any misconduct or disciplinary issues.Moreover, schools provide a safe and secure environment for students. They have security measures in place to ensure the safety of students within the school premises. Schools also have counselors and psychologists who provide guidance and support to students facing personal or emotional challenges.In conclusion, schools are essential institutions that provide education, skills, and knowledge to students. They offer a wide range of subjects, extracurricular activities, libraries, labs, and field trips to enhance the learning experience. Schools also promote discipline, good behavior, and provide a safe environment for students to grow and develop.hello taya"
result += "School is an institution where students go to receive formal education. It plays a crucial role in shaping the future"
result = re.split('[.,\s]', result)

for i in result:
    if (i != ''):
        file.write('4\n')
        file.write(i)
        file.write('\n')

file.write('6\n')

# for i in range(999):
#     file.write('2\n')


for i in result:
    if (i != ''):
        file.write('3\n')
        file.write(i)
        file.write('\n')

file.write('5\n')        

# for i in range(999):
#     file.write('1\n')

file.write("0")