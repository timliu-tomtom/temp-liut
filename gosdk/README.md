Now we have a Hela team API key which can be used to develop GO SDK and NK2. 3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb .
You can specify this API key in the following places:
For building GO SDK, ~/.gradle/gradle.properties :

```
mapsApiKey=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb
searchApiKey=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb
trafficApiKey=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb
navigationApiKey=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb
routingApiKey=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb
```

For running NK2 C++ test cases, your ~/.bashrc or ~/.zshrc or wherever you export environment variables:
```
 export ROUTING_API_AUTH_TOKEN_KEY=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb
```
Automotive App's local.properties: nk2ApiKey=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb

NK2 developer app's command line argument: --api 3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb

The account used to register this API key is:
```
User name: geo_expansion_hela
Email: GeoExpansionHela@groups.tomtom.com
Password: Please contact 
@Robert Wu
 if you need
You can go to https://developer.tomtom.com/ and login with the above account to check the API key details.
```


current.txt

https://tomtomslack.slack.com/archives/C01MUJB0WQG/p1652964936108659

```
cmVmdGtuOjAxOjE2OTA0NDcwOTA6Tmt1cjNPd2NzbDMyR1RSYnpBRXVMY0p5MFB Z
```

```
abstract class(.|\n)*data class
interface(.|\n)*data class
```

```
https://tomtomslack.slack.com/archives/C02PTT6TM0X/p1671634677371909?thread_ts=1670938074.542939&cid=C02PTT6TM0X
traffic api key V3dJqXASQIqOGKBJzGST8ehwyWUrhhAk
```


doc question
* Android
** Where/how delopy
** how to update
** how to deploy image
** private in android not in ios ?

* iOS

@Piotr Jozwiak - GO SDK - grants access to customers for documentation
https://confluence.tomtomgroup.com/display/GOSDK/GO+SDK+Documentation+Guidelines
https://confluence.tomtomgroup.com/display/GOSDK/Epic%3A+HorizonEngine
https://confluence.tomtomgroup.com/display/GOSDK/Script+to+generate+a+demo+page


toward name
https://nds.tomtomgroup.com/webviewer/44547/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_LINK%26lon%3D14126048.393933%26lat%3D4516857.4386423%26scale%3D2300.7289714628446%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.92122799398234&lat=37.55536&lon=126.89801&layers=FFFBFFFFFFF00F0FFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true



User input: 인천국제공항 (Incheon International Airport)
For the poi 인천국제공항제1여객터미널(Incheon International Airport Terminal 1), the 제1여객터미널 (Terminal 1) is unmatched with the input and penalty is applied during scoring.
A fixed 15 penalty charged in  UnmatchedWordPenalty()
And a dynamic penalty based on text length is charged in UnmatchedCJkWordPenalty()


ODO_LOG_WARNING(kLogId, "TTDebug, ScoreOneDoc start, doc id {}, file id {}", doc.doc_descriptor.GetDocId(), doc.doc_descriptor.GetFileId());


  //const bool doc_imp = (doc.important == 1);
  //const bool poi_imp = IsNationalImportant(poi);
  const bool is_national_important = (doc.important == 1) && IsNationalImportant(poi);
  //ODO_LOG_WARNING(kLogId, "TTDebug, ScoreOneDoc doc_imp {}, poi_imp {} comb {}", doc_imp, poi_imp, is_national_important);

//std::cout << "TTDebug, name " <<  unicode_string << std::endl;

  //std::cout << "TTDebug, score {}" << match->GetScore() << std::endl;


 ```
 一開始是上次Tim分享過的，關鍵字經過tokenize之後，在PoiSearchEngineNds::SelectDocuments裡下sql query找出跟關鍵字match的結果，放到matched_docs裡面
下一步會將matched_docs排序，排序有兩種方式
SearchState::CmpDocs: 這是Marc在ticket裡面提到的"heuristic"，會看doc是不是national important、type是不是city，還有其他參數，不過今天我們要測試的這個case，type都是poi，其他屬性也都一樣，這些屬性對於這些matches沒有幫助
SearchState::CmpOnDistance: 顧名思義就是只用distance，從小排到大
這邊有個參數match_sort_distance_only_percentage_，設定是10 (我昨天誤會了應該是10才對)，首先會先用SearchState::CmpOnDistance把所有matches都排序一次。再來根據match_sort_distance_only_percentage_這個參數保留前10%的matches不動，剩下的90%會再用SearchState::CmpDocs排序一次。
也就是說距離近的還是會在前10%，就算是national important之類的doc，只要距離不夠近也不會排到最前面。
再來就是 BaseSearchEngineNds::ScoreDocs把排序過的matched_docs打分數，根據search_config裡面定義的 max_docs_to_score
最多只會把matched_docs的前100個結果拿去打分數。log可以看到這邊會寫"Scoring xxx of ooo document(s)"，就是只會把ooo個docs裡面的前xxx個拿去打分數。
打完分數之後會看到log "Finalizing xxx POI result(s)" 然後在 LocalMapSearchNds::GetPoiResults裡才會透過data access去拿poi的內容，可以參考search_util.cpp裡面的ReadPoiFromDatabase，到這個步驟才能拿到poi的內容，像是category、name、location...等內容。
``` 
 
#### Search
```
unicode string -> 2 byte
std::String -> utf8 -> 2 or 3 or 4 byte
w2s -> unicode to std::string to print
CName is unicode string
```


####
```
update_conan=true 不要設 -> 部會重build binding, 會重artifactory抓
```

#### 
```
https://a.api.tomtom.com/traffic/map/4/tile/incidents/{z}/{x}/{y}.pbf?key={mapKey}&tags=[road_category,road_subcategory,icon_category,magnitude,delay,left_hand_traffic,description]

TW
https://kr-api.tomtom.com/traffic/map/4/tile/incidents/6/53/26.pbf?key=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb&tags=[road_category,road_subcategory,icon_category,magnitude,delay,left_hand_traffic,description]

KOR
https://kr-api.tomtom.com/traffic/map/4/tile/incidents/11/1747/792.pbf?key=3jJp7KBqWRBzwCCf9fMSuiJUwnFAHSRb&tags=[road_category,road_subcategory,icon_category,magnitude,delay,left_hand_traffic,description]
```
