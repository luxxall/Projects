-- Keep a log of any SQL queries you execute as you solve the mystery.
-- first look at whats going on
SELECT description FROM crime_scene_reports
    WHERE day = 28 AND month = 7
    AND street = 'Humphrey Street';

-- check interviews
SELECT transcript FROM interviews
    WHERE day = 28 AND month = 7;

-- check all atm transactions at the robbery day
SELECT * FROM atm_transactions
    WHERE day = 28 AND month = 7
    AND atm_location = 'Leggett Street';

-- search for names of people that used atm
SELECT name FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
        WHERE day = 28
        AND month = 7
        AND atm_location = 'Leggett Street';

-- check for parking lot logs for vechicles that left after 10
SELECT * FROM bakery_security_logs
    WHERE day = 28 AND month = 7
    AND hour = 10 AND minute > 15;

-- print names of people that left parking lot
SELECT people.name, bakery_security_logs.hour, bakery_security_logs.minute FROM people
    JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
        WHERE day = 28 AND month = 7
        AND hour = 10 AND minute > 15;

-- call for 28.07 that duration is less that 1 minute
SELECT * FROM phone_calls
    WHERE day = 28 AND month = 7
    AND duration < 60;

-- point names to calls above
SELECT people.name FROM people
    JOIN phone_calls ON phone_calls.caller = people.phone_number
        WHERE phone_calls.day = 28 AND phone_calls.month = 7
        AND phone_calls.duration < 60;

-- flights on 29.07 with names, time and destination. I assumed that 'early' is < 9
SELECT people.name, flights.hour, flights.minute, airports.city
FROM people
    JOIN passengers ON people.passport_number = passengers.passport_number
    JOIN flights ON passengers.flight_id = flights.id
    JOIN airports ON destination_airport_id = airports.id
    WHERE flights.day = 29 AND month = 7
    AND hour < 9;

-- combine all information to select a person that appears in all places
SELECT DISTINCT people.name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.destination_airport_id = airports.id
WHERE flights.day = 29 AND flights.month = 7
    AND flights.hour < 9 AND phone_calls.day = 28
    AND phone_calls.month = 7 AND phone_calls.duration < 60
    AND bakery_security_logs.day = 28 AND bakery_security_logs.month = 7
    AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute > 15
    AND bakery_security_logs.minute <= 25 AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.day = 28 AND atm_transactions.month = 7;

-- the only person that is listed on every evidence is Bruce and his fly destination was NYC.
-- I will now check who helped him
SELECT people.name FROM people
    JOIN phone_calls ON phone_calls.receiver = people.phone_number
        WHERE phone_calls.day = 28 AND phone_calls.month = 7
        AND phone_calls.duration < 60 AND phone_calls.receiver = '(375) 555-8161';


