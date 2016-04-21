word = 'a loooooooog word'
num = 12
string = 'bang!'
total = string * (len(word) - num)
print(len(word))
print(total)

phone_number = '1386-666-0006'
hiding_number = phone_number.replace(phone_number[:9], '*')
print(hiding_number)


search = '168'
num_a = '1386-168-0006'
#print(search + ' is at ' + str(num_a.find(search)) + ' to ' + str(num_a.fiind(search)))

print('{} a word she can get what she {} for.'.format('With', 'came'))
print('{preposition} a word she can get what she {verb} for'.format(preposition = 'With', verb='came'))
print('{0} a word she can  get what she {1} for.'.format('With', 'came'))

# input("nihao")


def nihao():
    return 'nihao'

def fahrenheit_converter(C):
    fahrenheit = C*9/5+32
    return str(fahrenheit) + '%f'

fahrenheit_converter(32)


chang = 3
kuang = 4
xie = chang * chang + kuang * kuang
print('The right triangle third side\'s lengh is',xie ** 0.5)

print('   *','  * *',' * * *','   |   ',sep='\n')



def text_filter(word, censored_word = 'lame', changed_word = 'Awesome'):
    return word.replace(censored_word, changed_word)
def text_create(name, msg):
    desktop_path = './'
    full_path = desktop_path + name + '.txt'
    file = open(full_path, 'w')
    file.write(text_filter(msg))
    file.close()
    print("done")

text_create('nihao', 'lame\n')
