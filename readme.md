
# C++ Notification System – Strategy Pattern

Šis projektas demonstruoja **Strategy dizaino šabloną** siunčiant pranešimus (el. laiškus ir SMS). Yra bazine klasė `Notifier`, iš kurios paveldimos strategijos:

- `EmailNotifier` – siunčia el. laiškus per `libcurl`
- `SMSNotifier` – siunčia SMS per Twilio API

## Projekto struktūra

```
.
├── demo.cpp                        # Pagrindinis demonstracinis failas
├── test.cpp                        # Testai su FakeNotifier
├── notifier.hpp                    # Bazinė abstrakti klasė Notifier
├── emailNotifier.cpp               # Email siuntimo strategija
├── smsNotifier.cpp                 # SMS siuntimo strategija
├── MessageSender.hpp               # Stabili/Pastovi klasė
├── Makefile                        # Kompiliavimo ir paleidimo automatizacija
└── README.md                       # Šis failas
```

## Reikalavimai

- **GCC** su C++17 palaikymu
- **libcurl** biblioteka (suinstaliuota)
- Windows: naudok `MSYS2` arba `Git Bash`
- Linux/Mac: turi veikti su `make`

## Kompiliavimas ir paleidimas

1. Atidaryk terminalą šiame aplanke.
2. Paleisk:

```
make all
```

## Paleidimas

```
make run_demo   # paleidžia demo (realus siuntimas)
make run_test   # paleidžia testą su neigyvendinta klase
```

## Valymas

```
make clean    
```

## Dizaino šablonas

Projektas naudoja **Strategy Pattern**, kad būtų galima lengvai keisti siuntimo logiką (el. paštas / SMS / testinis siuntimas), išlaikant bendrą sąsają (`Notifier`) ir modulinį dizainą.
