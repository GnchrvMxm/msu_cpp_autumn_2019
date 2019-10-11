import sys

def safe_input():
    try:
        return input()
    except EOFError:
        sys.exit(0)
		
Voprosy = [None] * 9
Otvety = [None] * 11
Otrezok = 10**5
Tochka = 0

while(True):
	#Новые вопросы
	ostatok = 0
	check = 0
	x = int(Otrezok) // 10	
	for i in range(9):
		Voprosy[i] = Tochka + x*(i+1)
		print('?', Voprosy[i]) #Вопросы
	if (Tochka == 99990):
		check = 1
		print('?', 100000)
		
	print('+')
	
	#Новые ответы
	Otvety[0] = 0
	Otvety[10] = 1
	for i in range(1, 10):
		Otvety[i] = int(safe_input()) 
	
	#Ответы
	if (check == 1):
		Tochka += (1 - int(safe_input()))
	
	#Новый отрезок и точка
	Tochka += x*(Otvety.index(1) - 1)
	#print(Tochka)
	Otrezok /= 10
	
	if Otrezok == 1:
		otvet_na_zagadku = Tochka
		break

print('!', otvet_na_zagadku)