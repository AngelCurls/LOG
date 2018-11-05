import random

def arrayToString(array):
    return ''.join(array)

def createRandomArray():
    array = []
    for i in range(0, 2500):
        rnd = random.randint(0, 15)
        if(rnd == 1):
            array.append('1 ')
        elif(rnd == 2):
            array.append('2 ')
        elif(rnd == 3):
            array.append('3 ')
        else:
            array.append('0 ')
    return array

def writeFiles():
    # Lista de niveles que quieren cambiar
    levelsToCreate = [1, 2, 3, 4, 5]

    if 1 in levelsToCreate:
        file = open("2500array1.txt", "w")
        file.write(arrayToString(createRandomArray()))
        file.close()
    if 2 in levelsToCreate:
        file = open("2500array2.txt", "w")
        file.write(arrayToString(createRandomArray()))
        file.close()
    if 3 in levelsToCreate:
        file = open("2500array3.txt", "w")
        file.write(arrayToString(createRandomArray()))
        file.close()
    if 4 in levelsToCreate:
        file = open("2500array4.txt", "w")
        file.write(arrayToString(createRandomArray()))
        file.close()
    if 5 in levelsToCreate:
        file = open("2500array5.txt", "w")
        file.write(arrayToString(createRandomArray()))
        file.close()

writeFiles()