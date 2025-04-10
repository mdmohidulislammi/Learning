def args_and_kargs(*numbers, **addition):
    for num in numbers:
        print (num)
    for key, value in addition.items():
        print(key, value)
    print(addition['my'], addition['title'])
args_and_kargs('one', 'two', 'three', 'four', my='name', title='Islam')