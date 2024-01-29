Zoo Tycoon

* Inheritance in C++ 

Problem Statement:

*  Small game where the player acts as the owner of the city's zoo, which has exhibits of monkeys, sea otters, and meerkats. As the owner, it's the player's job both to ensure the welfare of the animals and to generate as much profit as possible. They accomplish these goals by investing in animals, feeding them, caring for them when they are sick, and raising their babies when they are born.

Each species of animal has these specific traits:

Age:

* For all species, an animal is a baby if it is less than 5 weeks old.
* For all species, an animal is an adult if it is at least 2 years old.
* Clarification: For our purposes the age range between 5 weeks and 2 years can be considered as adolescence. The animal is no longer a baby but is not yet capable of reproducing.

Cost:

* Monkeys cost $15,000 each.
* Sea otters cost $5,000 each.
* Meerkats cost $500 each.

Babies:

* Monkeys have 1 baby at a time.
* Sea otters have 2 babies at a time.
* Meerkats have 5 babies at a time.

Food cost:

* The base daily food cost varies on a week-to-week basis (see below).
* Monkeys have a weekly food cost of 4 times the base food cost.
* Sea otters have a weekly food cost of 2 times the base food cost.
* Meerkats have a weekly food cost equal to the base food cost.

Revenue:

* Each animal generates weekly revenue equal to a percentage of the initial cost of one of its species.
* All animals except monkeys generate 5% of the cost of one of their species (i.e. each sea otter generates $250 each week, and each meerkat generates $25 each week).
* Each monkey generates 10% of the cost of a monkey (i.e. each monkey generates $1500 each week).
* On certain weeks, when attendance is high, each monkey generates some amount of bonus revenue. See below for details.
