
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
