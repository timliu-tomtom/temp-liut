
### H-Search ###
| Criterion | selectionCriterion |namedObjectClass | 
| --- | --- | --- |
| A | 0 | 0 COUNTRY |
| B | 9 | 2 ORDER_1 |
| C | 1 | 9 ORDER_8 |
| D | 6 | 10 ORDER_9 |
| E | 17 | 24 NEIGHBORHOOD |


| H-search and reverse| clientlib-common-Address | nk1-reverse-geo |
| --- | --- | --- |
| Country | Country | 
| Prefecture | State | stateName
| Municipality | City | cityName
| Oaza | CityDistrict | districtName
| Chome/aza | CityBlock | localityName
| House number | HouseNumber


nk1-VHCommon-Model-Imp-VH-Proto-SafetyLocationEntry.proto

nk1-VHCommon-Model-Imp-VH-Proto-SafetyLocationProvider.proto ?

### Safety location in VH ###

nk1-Routing-RouteInfo-Api-ICameraProvider.h

../Engines/MapMatching/DrivingAssistance/VehicleHorizonCommon/SafetyLocation/Interface/TomTom/NavKit/VehicleHorizon/SafetyLocation/SafetyLocationData.h

../Engines/MapMatching/DrivingAssistance/Model/Implementation/TomTom/NavKit/VehicleHorizon/Protobuf/PathSafetyLocation.proto
nk1-VHCommon-Proto-Api-Imp-Converter-PathSafetyLocationConverter

### Online routing ###
nk2-trip-onboard -> http request -> NKWorkerService (docker) -> thrift -> NKWorkerEngine (docker, nk1) -> Routing engine (as a lib of NKWorkerEngine)

build NKWorkerService 和 NKWorkerEngine 會產生各自的 docker image (系統須裝docker, 看起來是用/usr/bin/docker)
run-processes-nkw 可以跑 NKWorkerService 和 NKWorkerEngine 在 docker 裡
run docker可以跑起來, 有web demo tool loccalhost:5000 

For debugging, `run-processes-nkw -no-engine` and 自己跑 `nk1/bin/NKWorkerEngine` , 就可以看到NKWorkerEngine的log, breakpoint...

e2e test
run-e2e-test.py (start server)
再用intellij open nk2-e2e-test and run

有VPN的話, ifconfig會看到 mtu xxxx
要把docker-setup script裡面mtu的值改成該值

press ctrl+c only ONCE and wait it gratefully stop (close virtual internet), do not force stop, force stopping may cause virtual network not close properly and impact normal network access.

docker image prune -a (清掉沒在用的docker image)

需裝ant


### ASAN ###

https://jira.tomtomgroup.com/browse/NAV-81770


### Tollgate instruction ###
HCP3\
  map contains TOLL_ENTRY/TOLL_EXIT, TOLL_GATE_PAYMENT_TYPE, MASK\
  DataAccess implemented in GuidanceDataReader with TollBoothPlaza\
  https://bitbucket.tomtomgroup.com/projects/NAVKIT/repos/dev-geoexpansion/pull-requests/228/overview
  
  RoutingDataPerTile -> TTollBoothPlazasStorage\
  RoutingDataPerTile -> TTollBoothPaymentTypesStorage

  Instruction engine implemented with TollBoothPlaza\
  https://bitbucket.tomtomgroup.com/projects/NAVKIT2/repos/nk2-navigation-instruction-engine/pull-requests/1232/overview

  map does not have tollgate name\
  
Caruso2\
  map contains TOLL_PAYMENT_TYPE, MASK\
  DataAccess implemented with LandGuidanceReader\
  https://bitbucket.tomtomgroup.com/projects/NAVKIT/repos/dev-geoexpansion/pull-requests/53/overview
  https://bitbucket.tomtomgroup.com/projects/NAVKIT/repos/dev-geoexpansion/pull-requests/73/overview

  The implementation in instruction engine with TollBoothPlaza does not work for get payment type\
  Potential solution 
   * Handle [TOLL_PAYMENT_TYPE, MASK] in GuidanceDataReader and stored to TTollBoothPaymentTypesStorage as well\
   * Instruction engine introduce own tollgate struct combine plaza and RoutingData::GetPaymentType(arc)\ 





### CLion debug ###
run search-onboard-service-app, (in conan build, specify searchlib:build_type=debug (since artifactory is release, make debug will pull down and re-build))which use searchlib
go to build, find xxx.cmake find searchlib hash code
open .conan/<hash code>/xxx.cpp and set break point

```
gdb> p (char*) admin_area_names.country_code
```
https://stackoverflow.com/questions/46782354/c-debug-window-showing-incomplete-type-for-string-variable






```
/code/navigation-instruction-engine/src/situation_handlers/../lane_guidance/lane_guidance_builder.hpp:23:10: error: 'TomTom/NavKit/MapDataAccess/Map/Map.h' file not found [clang-diagnostic-error]
#include <TomTom/NavKit/MapDataAccess/Map/Map.h>

clang-tidy-10  -p=./build ./navigation-instruction-engine/src/get_full_instruction_list_specialization.hpp
clang-tidy-10  -p=./cmake-build-debug --checks="readability-*" ./poidetails-onboardservice/test/unit/onboard_poi_service_test.cpp
clang-tidy-10  -p=./cmake-build-debug --warnings-as-errors="readability-identifier-naming" ./poidetails-onboardservice/test/unit/onboard_poi_service_test.cpp
```


```
  AddressProcessor::Populate()
      InitializeAddressParts();
      PopulateAddressFromAttribute(address_builder);
      PopulateAddressFromClosestRoad(*location_, address_builder);
             PopulateAddressFromAdminAreaNames()
                    address_builder.WithMunicipalitySubdivisionName(order9);
                    address_builder.WithCityName(std::move(order9));
                    address_builder.WithMunicipalityName("");
         
      FinalizeAddressParts(address_builder);

      <feature type="nt_container" index="95">
                                <linkId type="uint16_t">293</linkId>
                            </feature>
```

                            https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D2410%26updateRegionId%3D2700%26namedObjectId%3D29413%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999479492&lat=22.6085&lon=120.2738&layers=FFFBFFFFFFF000FFFTTF0000TT&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://stackoverflow.com/questions/38950802/how-to-display-line-numbers-in-side-by-side-diff-in-unix
```
sdiff -l ../../old.txt ../../new.txt | cat -n | grep -v -e '($'
```
            
207246 70276 麥當勞-府中

新光

https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D13527035.739219%26lat%3D2881354.1438284%26scale%3D1821.844205863098%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.291537549196&lat=25.04565&lon=121.51496&layers=FFFBFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D13527981.353484%26lat%3D2881414.6149003%26scale%3D1821.844205863098%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.291537549196&lat=25.04585&lon=121.52427&layers=FFFBFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D13527377.884602%26lat%3D2881367.6840997%26scale%3D1821.844205863098%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.291537549196&lat=25.04558&lon=121.51868&layers=FFFBFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


catId 273

```
SELECT l.poiId, l.catId, r.isBrand from poiTable l INNER JOIN poiCategoryTable r where l.catId == r.isBrand AND r.isBrand is 1
```

https://nds.tomtomgroup.com/webviewer/43927/?action=FeatureInfo%3Flang%3DGBR_eng_Latn%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D1484169.1182216%26lat%3D6892336.6371566%26scale%3D2132.7295838497844%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18&lat=52.50723&lon=13.3344&layers=FFFBFFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=GBR_eng_Latn&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true



充電スタンド(急速充電) (1901)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3D*_*_Jpan%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D37537140%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999516927&lat=33.60127&lon=133.61461&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=*_*_Jpan&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


充電スタンド(一般充電) (1902)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3D*_*_Jpan%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D17278780%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999516927&lat=32.93867&lon=130.55902&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=*_*_Jpan&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

充電スタンド(一般充電コンセント型) (1903)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3D*_*_Jpan%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D86511060%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999516927&lat=34.6463&lon=135.51076&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=*_*_Jpan&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

充電スタンド (40916)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D43834580%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=16.999999999516927&lat=34.0422&lon=131.9126&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


https://nds.tomtomgroup.com/webviewer/43466/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D16459549%26updateRegionId%3D4235%26buildingBlockId%3D32%26poiId%3D1223152%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.00000000000776&lat=52.38399&lon=4.83602&layers=FFFBFFFFFF00F0FFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


metadata
  def[13]
    typeId 60 (POIATTR_EVS_CHARGING_SPEED = 60)
      index 0 numeric 1 -> 150  (speed normal)
      index 1 numeric 2 -> 152  (speed fast) 

  def[14]
    typeId 61 (POIATTR_EVS_CONNECTOR = 61)
      index 0 numeric 1 -> 51
      index 1 numeric 2 -> 58  (connector) 
      index 2 numeric 3 -> 81  (connecto CHADEMO)


Hi Hiroaki Ano,

1.

we are creating an EV charging station POI (category) for "Highway SA/PA facility category" separately from the existing EV charging station POI for Genre Search (showInSearchTree=1)

Yes this is what I required, and please set the standard category to POICAT_EVS_CHARGING_STATION, similar to other HW mode poi categories

POI names match category names (e.g., EV charging stations)

I am afraid I am not familiar with the real case in Japan, does EV station has a name in real world (e.g. fuel station has name ENEOS, SOLATO) ? if yes it is good to follow fuel station, if not naming it "EV charging station" is ok

Only one POI shall be created even if there are two or more charging stations in SA/PA

Is it possible to make it aligned with the ev poi for search? If in real world or search there are multiple charging station in SA/PA, put multiple HW mode ev poi in SA/PA

Same coordinates (mortonCode) as SA/PA POI shall be used.

Looks good, thanks

For each category, the icons you provided shall be set

Looks good, thanks

And I missed one thing, please also put the connector type(POIATTR_EVS_CONNECTOR), charging speed(POIATTR_EVS_CHARGING_SPEED), and number of slots(POIATTR_EVS_NO_CHARGING_STATIONS) in secondary attributes, same as the general ev poi for search. So application can also offer the information in HW mode


2.

The target for this implementation is the data for April 2023

Does it mean this implementation will be delivered after April 2023?

the same specification will be used and stored for the Giorgio data as well

It is mainly for Caruso and BMW, meanwhile I notice BMW is not available in jira Product field, Hiroaki Ano san are you able to add it ?
For Giorgio it is not clear yet, Vic Chen, Roland de Jong, do you have some feedback ?


https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D15559859.064718%26lat%3D4253892.1702139%26scale%3D1066.3647919248922%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=19&lat=35.65975&lon=139.77671&layers=FFFBFFFFFT0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://nds.tomtomgroup.com/webviewer/44055/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D15559896.551324%26lat%3D4256812.7423745%26scale%3D1066.3647919248922%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.2243933627806&lat=35.68151&lon=139.7735&layers=BFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


2022-08-31T16:00:40.539Z [info]    PoiDetailsImpl: poi_details_impl.cpp:155: Query: request {poi-id: nds:2213:2906:135140, language: ja-JP}, utc: 2022-08-31T16:00:40Z
TTDebug, Populate start
TTDebug, after InitializeAddressParts
TTDebug, address part 3, 
TTDebug, address part 4, 東京都
TTDebug, address part 11, 中央区
TTDebug, address part 12, 日本橋
TTDebug, address part 14, 2丁目
TTDebug, address part 23, 
TTDebug, after PopulateAddressFromAttribute
TTDebug, address{neighborhood_name: "2丁目", city_name: "中央区", municipality_subdivision_name: "日本橋", municipality_name: "中央区", sub_country_name: "東京都", country_code: "JPN"}
TTDebug, after PopulateAddressFromClosestRoad
TTDebug, address{neighborhood_name: "2丁目", city_name: "中央区", municipality_subdivision_name: "日本橋", municipality_name: "中央区", sub_country_name: "東京都", postal_code: "103-0026", country_name: "日本", country_code: "JPN"}
TTDebug, after FinalizeAddressParts
TTDebug, address{neighborhood_name: "2丁目", city_name: "中央区", municipality_subdivision_name: "日本橋", municipality_name: "中央区", sub_country_name: "東京都", postal_code: "103-0026", country_name: "日本", country_code: "JPN"}
2022-08-31T16:00:40.631Z [info]    PoiDetailsImpl: poi_details_impl.cpp:159: Query: POI {id: "nds:2213:2906:135140", names: [ "日本橋兜町駐車場" ], location: {coordinate: {latitude: 35.680940, longitude: 139.776930}, navigable_coordinates: [{latitude: 35.680955, longitude: 139.776938}]}, address: {neighborhood_name: "2丁目", city_name: "中央区", municipality_subdivision_name: "日本橋", municipality_name: "中央区", sub_country_name: "東京都", postal_code: "103-0026", country_name: "日本", country_code: "JPN", formatted_address: "東京都\n中央区\n日本橋\n2丁目"}, categories: [ "{ttom_category_id: 7313, nds_category_id: 54, names: ["屋内駐車場"], parent nds category ids: [], child nds category ids: [], is_brand: 0, is_browsable: 1}", "{ttom_category_id: 7313, nds_category_id: 503, names: ["駐車場＆充電"], parent nds category ids: [], child nds category ids: [], is_brand: 0, is_browsable: 1}" ], phone_numbers: [ "+81 3-3667-3351" ], opening_hours: {is_open_24h: true, local time ranges: [{date: 2022-09-01, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}, {date: 2022-09-02, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}, {date: 2022-09-03, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}, {date: 2022-09-04, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}, {date: 2022-09-05, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}, {date: 2022-09-06, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}, {date: 2022-09-07, {start_local_time: 00:00+09:00, end_local_time: 00:00+09:00}}]}, external_id: eb881339-3206-4000-8578-fa82848464ea, iana_time_zone: Asia/Chita, payment_methods: [ "kCash" ]}
2022-08-31T16:04:43.556Z [warning] LineAttributes: LineAttributes.cpp:347: Unknown (Nnds::Nbmd::EUnknown) road encountered
2022-08-31T16:04:43.556Z [warning] LineAttributes: LineAttributes.cpp:347: Unknown (Nnds::Nbmd::EUnknown) road encountered
2022-08-31T16:04:43.556Z [warning] LineAttributes: LineAttributes.cpp:347: Unknown (Nnds::Nbmd::EUnknown) road encountered
2022-08-31T16:04:44.160Z [warning] LineAttributes: LineAttributes.cpp:347: Unknown (Nnds::Nbmd::EUnknown) road encountered
2022-08-31T16:04:44.163Z [warning] LineAttributes: LineAttributes.cpp:347: Unknown (Nnds::Nbmd::EUnknown) road encountered
2022-08-31T16:04:44.194Z [warning] LineAttributes: LineAttributes.cpp:347: Unknown (Nnds::Nbmd::EUnknown) road encountered
2022-08-31T16:27:15.443Z [info]    PoiDetailsService: poidetails_service_core.cpp:54: Received POI request (poiId=nds:2213:2906:136683)
2022-08-31T16:27:15.443Z [info]    PoiDetailsImpl: poi_details_impl.cpp:155: Query: request {poi-id: nds:2213:2906:136683, language: ja-JP}, utc: 2022-08-31T16:27:15Z
TTDebug, Populate start
TTDebug, after InitializeAddressParts
TTDebug, after PopulateAddressFromAttribute
TTDebug, address{country_code: "JPN"}
TTDebug, after PopulateAddressFromClosestRoad
TTDebug, address{country_code: "JPN"}
TTDebug, after FinalizeAddressParts
TTDebug, address{country_code: "JPN"}
2022-08-31T16:27:15.448Z [info]    PoiDetailsImpl: poi_details_impl.cpp:159: Query: POI {id: "nds:2213:2906:136683", names: [ "YAYOI茅場町店" ], location: {coordinate: {latitude: 35.680325, longitude: 139.778230}, navigable_coordinates: [{latitude: 35.680496, longitude: 139.778090}]}, address: {country_code: "JPN"}, categories: [ "{ttom_category_id: 7315, nds_category_id: 64, names: ["レストラン"], parent nds category ids: [], child nds category ids: [], is_brand: 0, is_browsable: 1}", "{ttom_category_id: 7315, nds_category_id: 3691, names: ["ファミリーレストラン"], parent nds category ids: [], child nds category ids: [], is_brand: 0, is_browsable: 1}" ], external_id: 954be457-8298-4ffc-83fc-9c4f0cceb285, iana_time_zone: Asia/Chita}



2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ======== send ====
2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, number of seg 6
2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ============
2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, type POI
2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, uuid 138
2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, route entry 21500
2022-09-02 11:29:36.461 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, name Ebina SA
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, valid true
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, cate Category[LocalizedName:Service Areas Type:14 IconUri:tticon:///storage/emulated/0/Android/data/com.tomtom.navapp/files/maps/bundled/?db=NDS&bb=POI.NDS&bb_uri=PRODUCT/JPN&iconsetid=910]
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, loc Location[Coordinate[Latitude:35.431220 Longitude:139.401740] NavigableCoordinates[Coordinate[Latitude:35.434087 Longitude:139.402508],]]
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ============
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, type POI
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, uuid 140
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, route entry 21500
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, name Ebina SA
2022-09-02 11:29:36.462 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, valid true
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, cate Category[LocalizedName:Service Areas Type:14 IconUri:tticon:///storage/emulated/0/Android/data/com.tomtom.navapp/files/maps/bundled/?db=NDS&bb=POI.NDS&bb_uri=PRODUCT/JPN&iconsetid=910]
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, loc Location[Coordinate[Latitude:35.431220 Longitude:139.401740] NavigableCoordinates[Coordinate[Latitude:35.434085 Longitude:139.402507],]]
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ============
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, type POI
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, uuid 142
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, route entry 35100
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, name Ebina SA
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, valid true
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, cate Category[LocalizedName:Service Areas Type:14 IconUri:tticon:///storage/emulated/0/Android/data/com.tomtom.navapp/files/maps/bundled/?db=NDS&bb=POI.NDS&bb_uri=PRODUCT/JPN&iconsetid=910]
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, loc Location[Coordinate[Latitude:35.431220 Longitude:139.401740] NavigableCoordinates[Coordinate[Latitude:35.432995 Longitude:139.401813],]]
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ============
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, type POI
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, uuid 118
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, route entry 57300
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, name Ebina SA(Down)
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, valid true
2022-09-02 11:29:36.463 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, cate Category[LocalizedName:Service Areas Type:14 IconUri:tticon:///storage/emulated/0/Android/data/com.tomtom.navapp/files/maps/bundled/?db=NDS&bb=POI.NDS&bb_uri=PRODUCT/JPN&iconsetid=43]
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, loc Location[Coordinate[Latitude:35.431220 Longitude:139.401740] NavigableCoordinates[Coordinate[Latitude:35.431219 Longitude:139.401744],]]
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ============
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, type POI
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, uuid 156
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, route entry 57300
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, name エネオス
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, valid true
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, cate Category[LocalizedName:ENEOS Type:1 IconUri:tticon:///storage/emulated/0/Android/data/com.tomtom.navapp/files/maps/bundled/?db=NDS&bb=POI.NDS&bb_uri=PRODUCT/JPN&iconsetid=862]
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, loc Location[Coordinate[Latitude:35.431220 Longitude:139.401740] NavigableCoordinates[Coordinate[Latitude:35.431219 Longitude:139.401744],]]
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, ============
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, type POI
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, uuid 144
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, route entry 57300
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, name Ebina SA
2022-09-02 11:29:36.464 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, valid true
2022-09-02 11:29:36.465 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, cate Category[LocalizedName:Service Areas Type:14 IconUri:tticon:///storage/emulated/0/Android/data/com.tomtom.navapp/files/maps/bundled/?db=NDS&bb=POI.NDS&bb_uri=PRODUCT/JPN&iconsetid=910]
2022-09-02 11:29:36.465 9177-9177/com.tomtom.navapp D/DrivingHorizonRepository: TTDebug, loc Location[Coordinate[Latitude:35.431220 Longitude:139.401740] NavigableCoordinates[Coordinate[Latitude:35.431219 Longitude:139.401744],]]



#        if lang in lang_plural_form_mapping:
#            plural_catagory = lang_plural_form_mapping.get(lang)
#            if len(plural_catagory) == 1:
#                entry.msgstr_plural.pop()