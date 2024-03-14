def count_letters(text):
    letters = 0
    for i in text:
        if ("a" <= i <= "z") or ("A" <= i <= "Z"):
            letters += 1
    return letters


def count_words(text):
    words = 0
    for word in text.split():
        words += 1
    return words


def count_sentences(text):
    sentences = 0
    for i in text:
        if (i == ".") or (i == "!") or (i == "?"):
            sentences += 1
    return sentences


def avg_letters(letters, words):
    avg_letters = letters / words
    avg_letters *= 100
    return avg_letters


def avg_sentences(sentences, words):
    avg_sentences = sentences / words
    avg_sentences *= 100
    return avg_sentences


def main():

    text = input("Text: ")

    L = avg_letters(count_letters(text), count_words(text))
    S = avg_sentences(count_sentences(text), count_words(text))

    result = round(0.0588 * L - 0.296 * S - 15.8)

    if result >= 16:
        print("Grade 16+")
    elif result < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {result}")


main()
