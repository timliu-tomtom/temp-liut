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

     Caused by: java.lang.IllegalStateException: Instance has been closed.
        at com.tomtom.sdk.location.android.AndroidLocationProvider.checkNotClosed(AndroidLocationProvider.kt:229)

        Caused by: java.lang.IllegalStateException: Instance has been closed.
        at com.tomtom.sdk.location.android.AndroidLocationProvider.checkNotClosed(AndroidLocationProvider.kt:229)
        at com.tomtom.sdk.location.android.AndroidLocationProvider.removeOnLocationUpdateListener(AndroidLocationProvider.kt:187)
        at com.tomtom.sdk.map.display.location.DefaultLocationController.dispose(DefaultLocationController.kt:100)
        at com.tomtom.sdk.common.CompositeDisposable.dispose(CompositeDisposable.kt:48)
        at com.tomtom.sdk.map.display.TomTomMapProvider.close(TomTomMapProvider.kt:262)
        at com.tomtom.sdk.map.display.ui.MapView.onDestroy(MapView.kt:227)
        at com.tomtom.sdk.map.display.ui.MapFragment.onDestroy(MapFragment.kt:148)
        at androidx.fragment.app.Fragment.performDestroy(Fragment.java:3360)
        at androidx.fragment.app.FragmentStateManager.destroy(FragmentStateManager.java:781)