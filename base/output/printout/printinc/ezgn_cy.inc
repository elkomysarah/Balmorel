* File: ezgn_cy.inc

* Modified last time: 01-02-2002 by (rus), 16-02-2004 (ld), 20060328(hr)

* This file will print a table containing the total annnual electricity
* generation from new power technologies in each country.
* Electricity consumption for heat pumps are NOT included.


* -----------------------------------------------------------------------------

PUT ezgn_cy;

* First print headings:

if ((ezgn_cy.pw LT 32000),
ezgn_cy.pw = 32000;
PUT "Version:              " "%PRINTSEPARATOR%" SYSTEM.TITLE /;
PUT "File name:            " "%PRINTSEPARATOR%" "ezgn_cy.out" /;
PUT "Time-stamp:           " "%PRINTSEPARATOR%" SYSTEM.DATE " " SYSTEM.TIME  /;
$ifi %BB1%==yes PUT "Solved:               " "%PRINTSEPARATOR%" "BALBASE1"/;
$ifi %BB2%==yes PUT "Solved:               " "%PRINTSEPARATOR%" "BALBASE2"/;
$ifi %BB3%==yes PUT "Solved:               " "%PRINTSEPARATOR%" "BALBASE3"/;
PUT "Case-identification:  " "%PRINTSEPARATOR%" OCASEID.TS   /;

PUT "Total annual electricity generation from new technologies" /;
PUT "(Excl. electricity consumption at heat pumps)"/;
PUT "Units: GWh" //;

ezgn_cy.LJ = 1;

PUT "YEAR        " ; LOOP(C, PUT C.TL:12) ;PUT /;

);

* End of file headings.
* ------------------------------------------------------------------------------------


* -----------------------------------------------------------------------------



ezgn_cy.LJ = 2;

PUT Y.TL:4:0; PUT "        " ; LOOP(C, PUT ( EZGNqCY(C)*IOF0001):12:0 ; ); PUT /;
