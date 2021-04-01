from cs50 import get_string

text = get_string("Text: ")

letters = 0
words = 1
sentences = 0

for c in text:
    if c.isalpha() == True:
        letters += 1
    elif c == " ":
        words += 1
    elif c in [".", "?", "!"]:
        sentences += 1

L = float((letters / words)*100)
S = float((sentences / words)*100)

index = round (0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")s
else:
    print(f"Grade {index}")

