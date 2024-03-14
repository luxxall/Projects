import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database_name.csv dna_sequence.txt")
        sys.exit()

    # TODO: Read database file into a variable

    # path to database file
    database = sys.argv[1]
    import csv

    # create list for data from database
    rows = []

    # Read small version of database and read its data into dict
    # opens a file from the path and writes its data into a varaible
    with open(database) as file:

        # using Dict.Reader to read header from the file
        reader = csv.DictReader(file)

        # using append in a loop to write rows from database into a list
        for row in reader:
            rows.append(row)

    # TODO: Read DNA sequence file into a variable
    # path to dna sequence
    dna_path = sys.argv[2]

    # opens a file form dna path and writes its data into a varaible
    with open(dna_path) as dna_file:
        read_dna = dna_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # check which database is used to determine which STRs to search and rewrite
    # then convert them to ints to compare them later
    if database == "databases/small.csv":
        STR_repeats = []
        STR_repeats.append(int(longest_match(read_dna, 'AGATC')))
        STR_repeats.append(int(longest_match(read_dna, 'AATG')))
        STR_repeats.append(int(longest_match(read_dna, 'TATC')))

    elif database == "databases/large.csv":
        STR_repeats = []
        STR_repeats.append(int(longest_match(read_dna, 'AGATC')))
        STR_repeats.append(int(longest_match(read_dna, 'TTTTTTCT')))
        STR_repeats.append(int(longest_match(read_dna, 'AATG')))
        STR_repeats.append(int(longest_match(read_dna, 'TCTAG')))
        STR_repeats.append(int(longest_match(read_dna, 'GATA')))
        STR_repeats.append(int(longest_match(read_dna, 'TATC')))
        STR_repeats.append(int(longest_match(read_dna, 'GAAA')))
        STR_repeats.append(int(longest_match(read_dna, 'TCTG')))

    # TODO: Check database for matching profiles
    # variable for rows, when numbers in next if wont match, it iterates and changes row to another person
    row_index = 0

    # first condition to check which database im using
    if database == "databases/small.csv":

        # loop for checking each row, when row_index == len(rows) it means all comparisons were made and no matches found
        while row_index <= len(rows):

            # if every comparison has been made and still no matches then print not found and brake the loop
            if row_index == len(rows):
                print("No match")
                break

            # commpare each value and only when all of them matches print name
            elif (int(rows[row_index]['AGATC']) == STR_repeats[0]) and \
                (int(rows[row_index]['AATG']) == STR_repeats[1]) and \
                    (int(rows[row_index]['TATC']) == STR_repeats[2]):
                print(rows[row_index]['name'])
                break

            else:

                # when above condition is not true then add 1 to rows to check another persons numbers
                row_index += 1

    # database checking
    elif database == "databases/large.csv":

        # loop for checking
        while row_index <= len(rows):

            # after all comparisons if still not found match then print not found
            if row_index == len(rows):
                print("No match")
                break

            # check every each STR  and only if all are matched print name
            elif (int(rows[row_index]['AGATC']) == STR_repeats[0]) and \
                (int(rows[row_index]['TTTTTTCT']) == STR_repeats[1]) and \
                (int(rows[row_index]['AATG']) == STR_repeats[2]) and \
                (int(rows[row_index]['TCTAG']) == STR_repeats[3]) and \
                (int(rows[row_index]['GATA']) == STR_repeats[4]) and \
                (int(rows[row_index]['TATC']) == STR_repeats[5]) and \
                (int(rows[row_index]['GAAA']) == STR_repeats[6]) and \
                    (int(rows[row_index]['TCTG']) == STR_repeats[7]):
                print(rows[row_index]['name'])
                break

            else:

                # if even one condition is not true then add 1 to row and check another person
                row_index += 1

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
