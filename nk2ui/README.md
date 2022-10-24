
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


145663	赤稲田	102	1	23896153	23896156	23896450	23911458	24066644 984/3 = 328
                                   岩手県       金ケ崎町     西根



鹿児島市 -> 吉野町
大分県 中津市 その他

           C++                                 android 
           total  filtering incr      address  query filter    with addr      without addr
9500 h     0.130  0.081               0.11     0.16   0.1      1710kb         1025kb                  685-ﾍ 2270-ﾛ
1600 h                                                                                  ?
328 aza    0.011  0.003                                        63kb                          
 
北海道->鹿部町>本别


job?.cancel()
job = viewModelScope.launch {
    api.cancelAllOngoingTask()
	result = api.filter()
}

=========
api.cancelAllOngoingTask()
api.filter("A")
// job 1 cancel
api.cancelAllOngoingTask() // api.filter("A") is fished
api.filter("B")
===========


=========
api.cancelAllOngoingTask() (from job1)
// job 1 cancel
api.cancelAllOngoingTask()  (from job2)

api.filter("A") // wont do

api.filter("B")
===========

/////////////////////////////

job?.cancel()
api.cancelAllOngoingTask()
job = api.filter()


===
api.cancelAllOngoingTask()
job1 { api.filter("A", callback1) }

job1.cancel
api.cancelAllOngoingTask() // api.filter("A") is fished
job2 { api.filter("B") }
====
api.cancelAllOngoingTask() (from 1 call)
job1.cancel
api.cancelAllOngoingTask()  (from 2 call)

api.filter("A") // wont do

api.filter("B")


//////////////////////////////
// c++
class Api {
  cancelAllOngoingTask() {
    stop = true;
	blockUntilAllTaskFinished()
  }
  filter(string input) {
    stop = false;
    startNewTask(new FilterCandidateTask(input))

  }
  	
}



Ctrl + ALT + Q

Meanwhile I am wondering do we need to stuck in this topic in this PR?
Quote the beginning of the conversation
What do other Client’s do with regard to Locale? I’m not sure that the Client should have to retain additional state themselves, 
The other api do not provide user preferred locale in results either. For go-sdk user, he need to keep the preferred locale passed to api if he need it later. That is what we do globally, at least for now.




we are waiting for Zenrin to compile a newer map, but i’m not sure if it will use tomtom key or bmw key
(aug?)

we can do this to check Caruso is working
BMW map (data same as caruso) + nk1 + automovite ui

https://tomtomslack.slack.com/archives/G01FRT77JHY/p1659586126831779?thread_ts=1655280044.337799&cid=G01FRT77JHY


JVMIX  50815
JVSGN 117710
total 168525 


    @TestCaseIssueId("NAV-92185")
    @Test
    fun `should expose observed junction view tag`() = viewModel.junctionViewTag.observeForTestingBlocking {
        // GIVEN
        junctionViewTagFlow.value = "someTag"
        assertEquals("someTag", viewModel.junctionViewTag.value)
    }









































* MapDisplay provides junction view content -> 5sp

* Display junction view in horizon panel 
  ** Junction view fragment.kt   \
  ** hide uep, cm, etc tollgate  / 3sp (testing required)

  ** transition                 - 3sp (testing required)

* Enlarge junction view if required                                     \
                                                                         \ 
                                                                         \  3sp (testing required)
* Filter out tollgate junction view	                                   /
  ** option 1: if next instruction is tollgate, do not show jv (X)    /
  ** option 2: filter out jv if it is small (360x240)          (O)   /


* [placeholder] user settings
* [placeholder] click x to dismiss jv


* Prepare the test scope

* cucumber test



























