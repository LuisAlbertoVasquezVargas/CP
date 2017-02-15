largest = None;
smallest = None;
while True:
    n = raw_input("Enter a number: ");
    if n == "done" : break;
    try : 
        num = int(n);
    except :
        print "Invalid input";
        continue;
    if largest is None : largest = smallest = num;
    else : largest = max(largest,num) ; smallest = min(smallest,num);

print "Maximum is ", largest;
print "Minimum is ", smallest;