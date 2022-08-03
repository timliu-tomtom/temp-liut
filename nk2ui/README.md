
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


locationInputId	locationInputString	displayString	languageCode	priorityIndex	changeCaseMask	usageType	
955304	アサミトリカオカ	厚狭緑ヶ丘	112		23896153	23896188	23897722	24000173	24336524							                     厚狭緑ケ丘                       山口県       山陽小野田市   厚狭(大字) 





https://distro.cerence.com/

username: CerenceDistro@groups.tomtom.com

password: T0mt#mpassword

```

                horizon panel         display on map              search
---------------------------------------------------------------------------------
JCT/IC               X                   V (icon from map)     V (icon from UX)          
Rest area            V (icon from UX)    X                     V (icon from UX)  
tollgate             ?                   X                     V (icon from UX)
```



Alpha -> No guarantees, in development, crashes might happen (not to be enabled by Customers!)
	
Beta -> Feature is in development, but we want feedback via appcenter / drive tests (and could be enabled by Customers, with the asterisk that its under dev stil)
	
Prod -> Feature is done and UX is according to final specs.
```
0338285131
03 38285131
(03)38285131
03-38285131
03.38285131

+81 3-38285131
```

```
北海道茅部郡鹿部町本別
47390	アイカイク	I街区
47417	アールカイク	R街区				
47378	イーカイク	E街区	
```

```
chmod 2770 -> group rwx rws
chmod 4770 ->
```  