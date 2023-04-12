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