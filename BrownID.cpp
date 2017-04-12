/*

BrownID - an integral part of ShazYM
Does the fingerprint matching. Based on fingerprints generated by fpaclc (part of Chromaprint).
Written by ggn in 12th April 2017
Lollage, ideas and some code by dml.

*/

#include <stdio.h>

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>

unsigned int reference[] =
{
    2298218870,2296957271,2296961399,2288556407,2288818677,2288827901,2288828412,3379408892,3379412732,3375218428,1227742968,1228267224,1225261016,419950536,419916232,453339528,956656024,415594653,415594645,415332485,415333761,415448465,415446449,138614177,138558899,163741059,180550083,180521410,172002642,172004642,172011810,172012322,155234850,146846242,142651938,142668321,146814752,147012896,138557472,1208104995,1213598018,1280707010,1329400770,1314671554,1323106258,3466388850,3466404146,3466535218,2394894642,2394820914,2394816802,2394882339,2411476259,2310806819,2298236263,2296958311,2306383231,2339943805,2323228029,2323230072,3397365240,3396860408,3409435128,1228397528,1209162696,134381512,134377416,419523528,453012408,453015976,457210296,423722396,406945164,415333524,415464628,415399092,415464880,415464881,432209361,465747394,448970066,441490738,441488674,189829410,1262530850,1220653842,1220719378,1216541442,1216558867,1216428320,1216493856,3368171808,3368421680,3369994496,3480931136,3464073024,3472397888,3468272208,2394530163,2394530018,2394464482,2390261858,2386347110,2250507366,2251693182,2385914238,2365467230,2361272907,2294094409,2291665497,2291670648,2291672696,2295866968,2297984856,2289915256,2285782381,2285290989,2299971565,3372726236,3372592840,3640961736,3687099080,3414485705,3380673193,3380705963,3385006766,2302873518,3376546974,3368170686,3385013414,3380677798,3380677762,3418450051,3410077825,3405888720,1259445264,1259574528,1225962752,1259578624,1255255040,1251064848,1251039281,3394443299,3389143073,3389131041,3405909777,2286032387,2290491970,2291013314,2290962114,2291714786,2291722594,2295884130,2323126562,2319128834,2321167618,2329551106,2325357334,2325488423,2325481255,2348568423,2315046775,2306658175,2340216701,2340270045,2340006877,2340157949,3380599292,3376400892,1228888572,1226268120,1225162184,151482312,419785672,419720136,956332953,960592795,960592285,960592285,968980637,969111709,969096605,432233909,432242101,465829301,457424311,457285106,457217394,457216306,138522930,138523442,148091666,1221833490,1217638675,1216460085,1216477237,3364091941,3364026405,3368220677,3369520455,3388917190,3421358022,3421280214,3397232358,3397232374,3397362262,3393180247,1245692503,1245696855,1243575637,1243575797,1510958565,1515023861,1531798997,1540351957,1523570647,1514984439,3394040167,3394036070,3394036070,3402429735,2324559143,2341305639,2341436727,2307841397,2307839333,2358232551,2362294775,2362294771,2362295219,2362299299,2355073762,2354959090,2350774227,2350776149,3424648533,3424577877,3441093700,3474648132,3743085764,3730490820,3726229973,3743011301,3747344743,3713984375,3722372951,3722311191,3722278422,3713881687,3697096567,3697096679,3697030631,3705230819,3638252979,3634058691,3650745795,3688757203,3663591251,3665688083,1514108691,1513961235,1513960753,1513960737,1532965925,1499148325,1489514549,1489510519,1489790439,1506567671,1498217975,3679256053,3419205077,3419274709,3381589457,2307577153,2290799937,2290865489,2290799971,2290783587,2291764707,2379778018,2371389426,2407039954,2403046354,2403005382,2367353542,2367316807,2350605087,3424331039,3424336925,3424352381,3424221273,1226406089,1226366155,1226362315,1226427851,1501272030,1509667838,1509667327,1509667319,1241166327,3380277589,3378180433,3378181105,3629900769,3629868001,3638125537,3654939633,3722041331,3755597747,3730430391,3730700695,3726506391,3730701719,3732796823,3606958517,3607089597,3607089597,3598578605,3598574573,3598574589,3615483871,3581765599,1434287615,1434222063,1433763055,1467440383,1467368527,3614856519,3614954773,3613783349,3588552485,3588552501,3563452180,3572954368,3707174656,3702939409,3703004961,3706986019,3706730018,2641442594,2574456114,2339443762,2337281074,2337285170,2344643606,2340449542,2307055558,3380797334,3381059495,3418672549,3410808244,3407732100,3407541636,3407541636,3642684372,3625898996,3628070516,1480388148,1480387124,3629968164,3637836581,3688323605,3670415879,3401981702,3402044758,3397849574,3397845222,3414491302,3414430887,3380636837,3376475556,3372260784,1224969600,1258526144,1258399040,1241556240,1514188081,1522646321,1518583057,3671243827,3679632419,3640827171,2550570769,2282147329,2286837440,2295226048,2559446657,2560429985,2560363937,2577149091,2581347490,2346024082,2319674578,2315353138,2315375634,2315371794,2319508246,2327896598,2340479510,2340673142,2340607975,2344994276,2337587684,2300330436,2300465484,3641598220,3624821004,3624822072,3624676648,1477192488,1477258072,1481587401,1481055947,1489241994,1212416414,1212416430,1212481710,1212559550,1212310670,155348102,197323143,180551047,176348547,247580563,247518115,240182183,239133094,105111974,104952038,104882402,121659431,97677591,72544525,74637085,74767149,74763052,75336469,75401989,207259909,224105735,175669575,175735127,175804503,175829091,175824995,444457059,438165603,438263923,455042387,424490451,139270131,139269043,147665587,1221403575,1221419925,1221424085,1221588677,1221582413,3431975453,3433011743,3434977823,3451697951,2411503486,2394735086,2398929902,2390545390,2405389307,2371769195,2371773291,2371841325,3714054461,3714046029,3714054351,3716017359,3615028431,3610821007,1429946767,1362784663,1362765239,1348085159,1348154791,1373451681,1910338033,1943920977,1935532304,1398595888,1381818660,1394402084,1359791908,1359792676,1364085300,1406028292,1452174103,1452042534,1587289126,1591283766,1515851782,1243246598,1245339910,171598102,192505654,140017495,148463574,147447730,147716018,1221452194,1221419442,1221423507,1213198807,3360682967,3369072247,3364354613,3364870685,2359265821,2359139165,2375867757,2380059117,2413609453,2405221369,2405417977,2371810171,2371774315,2635983215,3692886383,3692922990,3693066446,3575489742,3581726863,3615342991,1434370525,1434342373,1434347365,1434349345,1935631905,1935503921,1935536721,1935467089,1918677748,1930220276,1930216356,1896661924,1896664556,1880082668,1973344364,4137609245,4137592846,4271679502,4271674398,4267671582,4198420494,4198391814,4181598230,4164821350,4171109350,2023555815,2023494372,2040280052,1531716548,1510744900,1510875716,1510875692,1531913772,3385605693,3368843789,3364878857,3633232716,3700329036,3701311180,3703341788,3719856872,3757888232,3732698089,3745461242,3711841770,3695130858,3694950634,3711916266,3715102922,3756846218,3752628618,1592557966,1592693150,3749638590,3749635047,3716080103,3722404711,3705501479,3705503537,3428810513,3430907649,3359472913,3359139089,3363370321,3380335953,3688531409,3667560433,3667509105,3671699249,3673799955,3665402898,3661464630,3661493286,4196163622,4212989990,2032017446,2027553574,2023359079,2023293668,2023232228,2026383060,1476929216,1476993728,1477059264,1212818160,1212756592,1221079888,1221343044,3368976196,3364813636,3482225476,3466562245,3468463813,3468461815,3467416558,3488412142,2373743086,2352837870,2350806118,2350802294,2350802294,2371805510,3489588038,3468329667,3467347648,2393474784,2657656736,2654514592,2654580144,3191514560,3191772096,3191772097,3191776113,3191726371,3208388646,3174835238,3158054950,3157198886,3165522278,3165260758,2645171910,3735630471,3736609413,3472388740,3464090260,3464492976,3464429456,3732926352,3728732112,3728601072,3728598609,3728597585,3728597745,1595762417,1595221985,1561673187,1599544819,1474104563,1457327347,1457339475,1456958483,1456958739,1459582739,1199568643,1198511874,1164690242,1148831730,1148835234,1148841382,1415183799,1415174295,1440337045,1474297077,1474161781,1459479605,1450042677,1466955573,1466883639,1433325111,1433390647,1433263671,1429036567,1430083159,1467290453,1467298293,1473585317,1473601703,1423401127,3570824343,3570847109,3570895237,3572861397,3572870005,3572869943,3563433782,2489694006,2539959606,2518996278,2653164582,2654278694,2658481191,2683773991,2576753959,2562070071,2562590211,2294023763,2291928803,2312638115,2306350003,2336176513,2336112000,2302024896,2299927632,3373743120,3372297472,3355454724,3376426261,3380619542,3380623670,3380615462,2306939238,2306955750,2307214758,2311439798,2311574918,2344985990,3418400132,3410003328,3410003328,3641935232,3641875920,3641884112,2031266064,2064820272,2048043024,2046995456,2046995456,4195548176,4195490849,4195490851,4212526370,2572553762,2560495186,2560562882,2560562898,2560430834,2291947234,2294077154,2315028211,2340196033,2319425217,2319367744,2386472512,2384375632,2384130016,2388389344,2656781716,2681865620,2681811124,2673619108,2606510244,3645845724,3641585677,3624808717,1478432063,1478432059,1478307611,1482435338,407661387,407694283,407685531,424462745,440917391,441905549,440856973,440856989,448979365,448913829,448848293,448831973,457221107,423670551,1010931478,1010933558,1011989286,1012120358,877919014,1951530806,1967321862,1963086599,1946304837,1409761780,1346650340,1355549924,1355548900,1439586772,1456368452,1456401221,1183771463,1184866630,3468669254,3468591190,3472785526,3470700647,3486294117,2647434340,2630724960,2630789076,2630780612,2631911156,2623391460,2623330021,2623299310,2572972014,2572971246,2602310894,2602376270,3675139150,3675139149,3662556252,3670945116,3666755404,3666812492,3683391180,3649861341,3364714222,3365361070,3369422246,3427028150,3439348886,3472909522,3456198099,1241736656,1262675280,1271068416,3386021632,3365113344,3432095249,3432099378,3436429090,3720711458,2638515490,2668399910,2584542262,2588535863,2588666149,2613734196,2614775380,2581220932,2581153476,2639812309,2639820518,2639029734,2647416038,2681031926,2613935190,2588764230,2320328773,2320461140,2320138100,2345291348,3419014724,3646637636,3361298261,3638121958,3638097126,3629962470,3645756662,3641572550,3406687430,1242327237,1242327516,1515154428,1515093724,1271811788,1234063044,1217224389,1217232534,1218276774,1287998626,1287998626,1279642802,3427136659,3443647697,3439453392,1292100688,1293088016,3444741888,3453195792,3448870451,3448811042,3448811298,3453074722,3745877026,3741633570,3742235666,3742346242,3747523842,3743072003,3745156867,3745156611,3714813458,3723202354,3706295346,3706318898,2624147506,2620928034,2620923942,2618892326,2623223663,2560178799,2560101101,2576878301,2576898767,2610485967,2597902031,2587415517,2587423053,3661258781,3678019644,3644465196,3627684156,1480203544,1480211272,1482308313,1490647705,1490610843,1506340491,1540146827,1541194635,1541390779,1541333417,1540251817,1506682300,1497841132,1498906092,1532391268,1532131157
};

unsigned int sample[] =
{
    //15 sec clip, 44khz
    155348102,197323143,180551047,176348547,247579539,247518115,240182183,239198630,105116070,104952034,105930978,122708007,97677591,72544525,74637085,74767149,74746660,75336453,75401989,207259909,223974663,175669575,175734871,175804503,175829091,175824995,444457059,438132835,438264947,455042515,424490451,139270131,139269043,147665587,1221403575,1221419925,1221424085,1221588677,1221582413,3431959069,3433011743,3434977823,3451698015,2411501438,2394735086,2398929902,2388513775,2405389307,2371769195,2371772779,2371841325,3714054269,3714046029,3714054351,3749571791,3615020239,3610821007,1429881231,1362784663,1362765239,1348085159,1348154787,1373451681,1910338033,1943920977,1935532304,1398595888,1398595876,1394406180,1359791908,1359792676,1364085268,1473141253,1452174103,1586260262,1587289126,1591414806,1511657478,1243246598,1245339910,171598102,158951222,148406103,148463574,147447730,147716018,1221452194,1221419443,1221423507,1213198807,3360682967,3368550007,3364354613,3364870685,2359265821,2359073629,2375865709,2380055023,2405220845,2405221369,2405352441,2371810171,2371774315,3709659503,3692886127
    //Same clip, 8khz
    //155348102,197323143,180551047,176348547,247579539,247518115,240182183,239198630,105116070,104952034,105930978,122708007,97677591,72544525,74637085,74767149,74746660,75336453,75401989,207259909,223974663,175669575,175734871,175804503,175829091,175824995,444457059,438132835,438264947,455042515,424490451,139270131,139269043,147665587,1221403575,1221419925,1221424085,1221588677,1221582413,3431959069,3433011743,3434977823,3451698015,2411501438,2394735086,2398929902,2388513775,2405389307,2371769195,2371772779,2371841325,3714054269,3714046029,3714054351,3749571791,3615020239,3610821007,1429881231,1362784663,1362765239,1348085159,1348154785,1373451681,1910338033,1943920977,1935532304,1398595888,1381818660,1394406180,1359791908,1359792676,1364085268,1473141253,1452174103,1586260262,1587289126,1591414806,1511657478,1243246598,1245339910,171598102,158951222,148406103,148463574,147447730,147716018,1221452194,1221419443,1221423507,1213198807,3360682967,3368550007,3364354613,3364870685,2359265821,2359073629,2375865709,2380055023,2405220845,2405221369,2405352441,2371810171,2371774315,2635917679,3692886127
    //Same clip, 1khz
    //432158081,432111025,432045475,432076195,1531049362,1531041730,1245877058,1245885186,1254273330,1271968034,3381702946,3633362210,3365123331,3365059841,3369254657,3361119024,3356937008,3357461328,3642675136,3641692112,3679319504,1515053520,1516200401,1516138577,1516130387,1516195923,1511878771,1511878754,1510745186,1531716966,1498179062,1506144247,1489428215,1485233879,1485692615,3637296727,3654071894,3687626326,3687691894,2597181046,2609772390,2614097255,2614091239,2580467173,2580465105,2639251393,2639262401,2631922417,2631783009,2623394657,2623297377,2619163985,2619280451,3709803731,3709762803,3680386291,3688774850,3688773058,3655300546,3646911938,3638514034,3638546786,3638423907,3638419763,3638354195,3655197011,3680363891,3663590899,3680501219,3680460785,3679412177,3679412177,3679410128,1540183408,1541240096,1524397361,1516070145,1516136193,1511937795,1511998259,1511871267,1531733287,1540121959,2043473399,1489890807,1489894838,1489827254,3636769206,3636769238,3628446678,3645241174,2605055862,2613444454,2609379686,2609831271,2609827319,2576338375,2312095175,2311832021,2378953717,2312877025,2312754016,2573006688,2568811888,2568803697,2569000305,2552161361,2552161731,2552161731,3630089667,3632186819,3632121811,3632134115,3657295843,3655202803,3646814195,3646744403,3646220115,3646289235
    //Same clip, 4khz
    //155610246,197323143,180551047,180542851,239190930,239129522,239133606,104980902,106160294,114319590,114319458,131096615,97677591,80933133,74637085,74767149,74746669,75336469,73304837,207522053,224236807,175669575,175735127,174755927,175829091,175824995,171827299,438132835,438264931,455042387,424490451,139270131,139269107,147665649,1221403637,1221419861,1221423701,1221588549,1221582413,3364850269,3431959135,3432880847,3449588702,2409400318,2394735022,2396836846,2405200878,2405397499,2371777387,2371773291,2371841325,3714054205,3713783885,3715889357,3615096013,3615020239,3610821007,1429881231,1362784663,1362765239,1350182309,1348416929,1373451681,1910333937,1943920977,1935532304,1381818672,1377624356,1394402084,1359791908,1359792676,1364085268,1406028293,1452174102,1586260262,1587289126,1524174870,1511657478,1243246598,1243242758,169500950,156854070,148406099,148463571,147447794,147716082,1221452258,1221419507,1221423571,1213199319,3360682839,3369074295,3364813429,3364805213,2358217421,2359135197,2375861741,2380055021,2405220845,2405221369,2371802105,2371773307,2371774250,3424446766,3692886062
};


static const int S[] = { 1, 2, 4, 8, 16 }; // Magic Binary Numbers
static const int B[] = { 0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF };

//#define min(x,y) (x>y?y:x)

// Lifted from https://bbs.archlinux.org/viewtopic.php?pid=759526#p759526
// with the addition of extension pattern matching
// and the conversion of everything into char* because O_o
using namespace std;

bool isDir(string dir) {
    struct stat fileInfo;
    stat(dir.c_str(), &fileInfo);
    if (S_ISDIR(fileInfo.st_mode)) {
        return true;
    }
    else {
        return false;
    }
}

#include <vector>
 
static std::vector<int*> fingerprints;
 
static int * add_fingerprint(int _size)
{
    int * fingerprint_ptr = new int[_size+1];
    // store the size as first int
    fingerprint_ptr[0] = _size;
    fingerprints.push_back(fingerprint_ptr);
    return fingerprint_ptr;
}
 
static void remove_all_fingerprints()
{
    // delete the new's and remove the vector entries
    while (!fingerprints.empty())
    {
        delete[] fingerprints.back();
        fingerprints.pop_back();
    }
}

void getdir(char *dir, vector<string> &files, const char *extension, bool recursive) {
    DIR *dp; //create the directory object
    char *dir_local=(char*)malloc(strlen(dir)+1);
    strcpy(dir_local,dir);
    struct dirent *entry; //create the entry structure
    int extensize = strlen(extension);
    if (dir[strlen(dir) - 1] != '/' && dir[strlen(dir) - 1] != '\\') {
        strcat(dir_local, "/");
    }
    dp = opendir(dir); //open directory
    char tempdir[1024];
    if (dp != NULL) { //if the directory isn't empty
        while (entry = readdir(dp)) { //while there is something in the directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { //and if the entry isn't "." or ".."
                strcpy(tempdir,dir_local);
                strcat(tempdir,entry->d_name);
                if (isDir(tempdir) == true && recursive == true) {//check if the new path is a directory, and if it is (and recursion is specified as true), recurse.
                    getdir(tempdir, files, extension, true); //recurse
                }
                else {
                    if (strcmp(&entry->d_name[entry->d_namlen - extensize], extension)==0)
                    {
                        files.push_back(tempdir);//add the entry to the list of files
                    }
                }
            }
        }
        (void)closedir(dp); //close directory
    }
    else {
        perror("Couldn't open the directory.");
    }
    free(dir_local);
}

int main(int argc, const char *argv[])
{
    int i,j;
    unsigned int minbits = -1;                  // The minimum amount of set bits for all windows

    //create the basic path to the directory using command-line argument
    char dir[] = "c:\\winstuff\\";
    //create the list of strings
    vector<string> files = vector<string>();
    //call the recursive directory traversal method
    getdir(dir, files, ".exe", true);
    //list all files within the list.
    //for (unsigned int i = 0;i < files.size();i++) {
        //std::cout << files[i] << endl;
        //printf("%s\n", files[i].c_str());
    //}

    // Sliding window within the range of the reference values
    for (i = 0;i < (sizeof(reference) - sizeof(sample)) / sizeof(int);i++)
    {
        unsigned int *windowstart = &reference[i];  // Start of reference buffer for current window
        unsigned int setbits = 0;                   // Total number of set bits in current window
        // XOR the reference and sample values and count the set bits
        for (j = 0;j < sizeof(sample) / sizeof(int);j++)
        {
            // https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
            // No idea if that's the fastest one - will have to experiment
            unsigned int v; // count bits set in this (32-bit value)
            unsigned int c; // store the total here

            v = windowstart[j] ^ sample[j];

            c = v - ((v >> 1) & B[0]);
            c = ((c >> S[1]) & B[1]) + (c & B[1]);
            c = ((c >> S[2]) + c) & B[2];
            c = ((c >> S[3]) + c) & B[3];
            c = ((c >> S[4]) + c) & B[4];
            setbits = setbits + c;
        }
        //printf("Window position=%d, number of set bits=%d\n", i, setbits);
        minbits = min(minbits, setbits);
    }
    printf("Least amount of set bits: %d\n", minbits);
}