args = [
    "asda",
    "test=====teasdasdst",
    "adiosndas"
]

newlist = list(filter(lambda s: s.count("test") >= 1, args))
           
print(newlist)
isTest = len(newlist) > 0

print(isTest)
