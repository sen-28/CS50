from sys import argv, exit
import csv

if len(argv) != 3:
    print("Usage: python dna.py database_file sequence_file")

file = open(argv[1])
reader = csv.reader(file)
seq = open(argv[2])
read = seq.read()

# function to find maximum number of repetions for an STR
def findvalue(tandem, i):
    value = 0
    while True:
        if tandem == read[i:(i + len(tandem))]:
            value += 1
            i += len(tandem)
        else:
            break
    return value

linecount = 0
match = 0
values = []


for row in reader:

    # first row
    if linecount == 0:
        # looping for each tandem
        for j in range(len(row) - 1):

            # value of STR assigned to tandem
            tandem = row[j + 1]
            # value for that tandem initialised to 0
            values.append(0)

            # for this STR, noting the number of repetitions in given sequence
            for k in range(len(read)):
                if tandem == read[k:(k + len(tandem))]:
                    #found a sequence
                    values[j] = max(findvalue(tandem, k), values[j])
        linecount += 1

    else:
        # looping for each tandem
        for j in range(len(row) - 1):
            if int(row[j + 1]) == values[j]:
                match += 1
            else:
                break

        if match == (len(row) - 1):
            print(f"{row[0]}")
            exit(0)

print("No match")
exit(1)












