
# C++ Notification System – Strategy Pattern

Šis projektas demonstruoja **Strategy dizaino šabloną** siunčiant pranešimus (el. laiškus ir SMS). Yra bazine klasė `Notifier`, iš kurios paveldimos strategijos:

- `EmailNotifier` – siunčia el. laiškus per `libcurl`
- `SMSNotifier` – siunčia SMS per Twilio API
- `FakeNotifier` – skirta testavimui (rašoma į failą)

## Projekto struktūra

```
.
├── demo.cpp              # Pagrindinis demonstracinis failas
├── test.cpp              # Testai su FakeNotifier
├── notifier.hpp          # Bazinė abstrakti klasė Notifier
├── emailNotifier.cpp     # Email siuntimo strategija
├── smsNotifier.cpp       # SMS siuntimo strategija
├── fakeNotifier.cpp      # Testams skirta strategija (į failą)
├── MessageSender.hpp     # Stabili/Pastovi klasė
├── Makefile              # Kompiliavimo ir paleidimo automatizacija
└── README.md             # Šis failas
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
make
```

Tai sukurs `demo.exe` ir `test.exe`.

## Paleidimas

```
make rundemo   # paleidžia demo (realus siuntimas)
make runtest   # paleidžia testą su FakeNotifier
```

## Valymas

```
make clean     # Ištrina demo.exe ir test.exe
```

## Testavimo elgsena

`test.cpp`:

- Tikrina ar `FakeNotifier` teisingai įrašė pranešimą į `test_output.txt`
- Tikrina ar visos `getLast*` funkcijos grąžina korektiškus duomenis
- Tikrina ar logai (`MessageSender`) veikia kaip tikėtasi
- **Testas nesikompiliuos**, jei `FakeNotifier` klasė nėra įgyvendinta

## Dizaino šablonas

Projektas naudoja **Strategy Pattern**, kad būtų galima lengvai keisti siuntimo logiką (el. paštas / SMS / testinis siuntimas), išlaikant bendrą sąsają (`Notifier`) ir modulinį dizainą.
