
### MVVM ###

View
 |
ViewModel - Model

ViewModel - Convert data from model to data can be easy consumed by view fragmant
limited business logic (should be in domain layer), mainly convert
https://github.com/tomtom-internal/nk2ui-main/blob/master/Documents/ArchitectureDocumentation/ArchitectureChapter1.adoc

E.g.
TripPlan has Avoid Set [toll, ferry]
ViewModel convert to [toll: true, ferry: true, unpave: false, SmartIC: false, ...] and goes to toggles in view (fragment)


SELECT locationInputString, criterionC, criterionD, COUNT(*) FROM sliCriterionDTable WHERE criterionC IN
  (SELECT criterionC FROM sliCriterionDTable WHERE locationInputString is null AND languageCode is 102)
 GROUP BY criterionC 

    locationInputString	criterionC	criterionD	COUNT(*)
	東京都 23896913  利島村	23936896	3
	23897134	23954891	3
	23897671	23996487	3
	23897803	24004798	3
	23898107	24018003	3

SELECT locationInputString, criterionD, criterionE, COUNT(*) FROM sliCriterionETable WHERE criterionD IN
  (SELECT criterionD FROM sliCriterionETable WHERE locationInputString is null AND languageCode is 102)
 GROUP BY criterionD


	locationInputString	criterionD	criterionE	COUNT(*)
	 函館市 23898966 滝沢町	24023925	3
	23899052	24023972	3
	23899355	24026012	3
	23899642	24027021	3
	23899649	24027031	3
	23899657	24027040	3
	23899659	24027044	3
	23899668	24027060	3
	23899670	24027061	3
	23899678	24027067	3
	23899686	24027075	3
	23899689	24027076	3
	23899690	24027077	3
	23899694	24027078	3
	23899698	24027079	3
	23899702	24027080	3
	23899704	24027083	3



	onNextSearchState() path 国
都道府県      -> state       isCountry   
市区町村         city        ,isMni
大字         
字           -> street      , isStreet
HouseNumber -> house number ,is Point address