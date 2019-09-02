#pragma once
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include "HQ.h"
using namespace std;
class Solution : HQ
{
public:
	Solution();
	~Solution();
	void Solve()
	{
		/*vector<string> words = { "foo","bar" };
		findSubstring("barfoothefoobarman", words);*/

		/*vector<string> words = { "bar", "foo", "the" };
		findSubstring("barfoofoobarthefoobarman", words);*/

		/*ector<string> words = { "word","good","best","word" };
		findSubstring("wordgoodgoodgoodbestword", words);*/

		/*vector<string> words = { "aaa","aaa" };
		findSubstring("aaaaaa", words);*/

		/*vector<string> words = { "ab", "ba", "ab", "ba" };
		findSubstring("abaababbaba", words);*/

		vector<string> words = { "vkyprpobkmsfzucyqzzfoafhyzca","gdvrupgnickwasnmjkouwvpegsgi","jzukeuphzuaityuhuvtaeyewpiih","syzqcnhfsbsdkalkyswuzzugfnrw","kygdtbrualfnleljxlclgfokqmas","pqoqebuckqhuuhtbqdfgmghlmwuq","ycrgpnqellshycigpjjycgwcumhx","vgogruifovqohxcdrjwroyazyfcm","lefxclawpssrdzerdrccffplkdxa","vyqhgvsvnjeciuhfazheupabuovy","fexbifznmmmgjkpxujkgpzrfyjfj","qthyvbpfnfwvycrzjhmeyvaogbop","rvvmbwsilazwwraroscbejyqcwbl","jzlafxodqxbpqsrviblaypnkmeyy","vrhzoqonyhhjotbhaptusljivfbr","trfvxektbhzilblororbyqcworpj","sybwxuozvleuiemfeqizmpeqxvzp","bxgdqeqawpblyyukmlarvzcitelf","tjxgahonlxwtcwxkpyuguaffktls","ebhyfvqjdjtzbspbkeuvcduxxhoy","rplhkfahmoqhaadszcjblctweonx","obxfaflsdlhdmxylrhdwykzavkch","hykrzhpevomytkehvbknbcgdmaky","tuvbtdssvcqwcvuslqdmsyjydufm","bkmtlhwrjyzyyddtbatzcidxbjzc","nrigldjggdadftzkotezlimeixel","tjqkgooiltthpzrdzefeuexocpzx","astpnufhcyhoivivxwphisiihvwz","plashuyjiesnbrqvhzkgxmlrmbho","ieaqcmstuwgffwdrshvlokbkjnjt","dewtgblfjkwcyvrravvjeiujaasv","hzeuvdirbumdcyhxvizqaspygypr","bbupkrinqdgjgvrlhdcsznylcynb","mwzmuyjvbijetxzatsszvmjrjqvw","lsxqakjrgasvjyjlowpcftohhuww","datwhkivbboennizwyovjwyonhvp","stuaudeckfedowdivplwbihqtpnx","chkctzauasvmkrsjaoprxzrrislk","sypcigotuopynwaoeyeqfibnuwyn","izwydmyiddxgojubqystzhtfmiof","rsrvmbrtlhkqvlfqfhnrcgnulqlc","tmfhkhutgxuwqxzvthbktergieip","kmpannhpuskxdrcrocfhkkdkvemq","pvyorisykimukboukjdbankosjpp","fahqbehiccxdwctcrrvuekrbkuok","nuuomzahttqkdndpdvwihzkknmxb","agpngnngkpsscbinvjbmjqbfsypt","zcbadxppoaeedlplihwqmzkoojbq","bgwnuxwefccdapcdkkxyvyptszoc","xzeszyrceeecuxmfsbxxnvyhalhu","evhpzgrskhlsrfmmrdqpqhwswelf","euithiooeoznstcvmsttsdbrrojd","ibdqmkcwrsnumdeyokzukqlushyo","babjxuqwfxaztvotnjqubmtcukts","kqjtsfdybufbqhlliiucdndjmhfd","csynisxanjxhkmrqfhylnszckigb","dtsecofjdxxasqhoxwcfuyqnbbnu","owkqffjiuctbhvweiybxmoxlisvv","kbxpfwtpbscqgpwrbnovwadlauty","nepadpepdjkomgepbzpageogtzkd","mmhnqadomhcbmwkmlgrneksazicq","rjgiafldvqxxcfujzptmnwnqfxdy","tgoxkvvptnawxvxanmbzrvuvaoua","oyalizczorcafuiepkdhlcmberie","wcnqcdsnljggxxemuhaafgskovak","tfcfchqhbbhmcpssduhfaljxdjtl","gdryqmitkpmzlrrkatuvmyaaqosd","zmhpnayyeggeqmkzwjyjrgezdweg","qflmwtjvztpacqkqsvellvommqia","rbhhafnwptozpkzshttdhtndhzzt","kqmxzeqirbvclxyhbxcuxuodlfil","epnbyezmlcalkfnkovaeydkixqsa","crczptixoatdlziutpbtqjzlaamu","avclbeabrswvvrhtzrildlwgbind","jbxctcorhjustkrewkpgcngtgodc","xwhefcqlhcnsihvgookjodzyxodc","vgmkhcjaegpzmalquakxknyvbojm","pjlhkvomadlrwzrnlsfsnayxtlad","rzheqwzoyzotzuhsfqfbailzkzkg","pbnzqcupteijdunudkdyjmqnjnxk","zxxdfwewhquwnupslmjbsroblzuu","zselvsrhoivrmoqgeldcdlakomfo","qjamzfvbuamftloiiyvbncrekvol","xyowodjulaxolcsnhsuzbptowtxz","puuaisjoluoiyzlnkjeulwlpliuj","dpzgcidailgxkvyaejjpivaqmpsk","mfbmwynonsyqpleatbmfhcgydkrl","qhpmmrrqbkzcliqnxihcfpjhcseh","pflktfyvnllruiwigexwsnaydqcw","mdedcacwrxxmeupejjzlcjeaqxpr","bnhwyageowozqjihjzmigrpaymqc","njsqglllijcwubytryptgrrfyype","moyhhigwywlxdtirojzoyuisiudd","gaxogxhijbbfyildgqwbzrondpzn","qpryukxkwhfgzuiklzwnurkhpkjf","rjzljakguagrmmlwszdxqlyeacuy","eivkgdkckgrbwhtbtytpkspdeyru","ikhkkfnrbunkmjgzfxrrkcuctifg","sdmscgtjvqxoxsprjvjzvunpzkqq","mywyzwcmikjplszmrammwcvizzjw","ixlcricllgqymubcsfmowxkzirrb","ahtrdntlhczsxncxonlyxrvkngab","lruntsuvmyiplowalkfvgibcaeiq","wqpnefqddjebadagpjtulhyjaovn","eiwzollynvytdpvrpghlgulthjol","tqfjzpfljszinvilqphopfejzpih","gnuknxvmulkbilbbirwwaoqdbmhx","ypouajvtsilpihkajobwvrviyhih","smlxvwawfweprbkghwouzfjsawmc","uvvuujswyovpkjdidhkjveoqvfbi","vyswdflcyptilsmrdmybrckasuvr","avnrfmeomqxjrfcfrqbjpfihsglt","rpdmydtakjqxjmtliqxaqrgkunqe","pmqbzwszwpzygmhkdcmdxtqmlhby","vvcejrnhqusawvrxwiyddulyjuxi","aounisgiepbkpthbtrmipbmuwcdg","nlhxitreyrjwbxwyxritnacahfcb","wivbthksxawvsbbynhowlgmahrzd","zxyptkiyprijwcndxjjhhmgvbeij","zgkytrpgtpgxxmcoaopwynhrtmqz","zgtbfppoxvrfuhongwujtblxqmyg","kvkuvdxdykoyvyuiwwqgmgdasydj","jouksvkvubmidtoiegtonqgbrrrf","yjnwbbsbmpuexhufpgiaujyratza","zflnytcpjwzegkyfwfejgnivzadk","eksafuanoibrmmdtavbcmxmizcjz","qyrilcggaieggkxzlhhvgvrfcbac","ayvliqyoycyunbgobcggcfgqhqvp","wqbeuwxoofeyiquijhwutnorkfvq","lgkjxzaffftnjlfamvoucfurecpj","yxzxzbwoalmtgvsqedsiuwhdlrcg","pdcblomjqnovukidvpgikwepebgi","lwaqmptmwsajwaxifktvitbgwlqv","zlnewjtfhcaxghjeqhzzzepgebvx","jowjfqjyveldplwricppcnwevsnk","hcnedrzcsqfwulyqlnwdovcbsaks","kwfjdrjylageqocncgdcusaughnb","mlgpzyxyaoliertcytgnosoplppp","nvstvhlitkktszzpzirqjbvptgxl","ccyfctbldlghpulckwdgusbfobtd","faqqsepulfecjzgwzfdaehubbkeo","dgksrupzpjfoaomdnjekamepngpw","dosfyaplgqelvhzemtjbatzybxxb","bbirsbqnlpzkyfsxbcimeebyxmhm","kirkjmytcwhcbiyojeelimtkracy","yruzsctlglytaxfyeyyfcgtgmxfk","fxtfxlfeswtoaqtwhsuzzhqrwusc","xzczpxnxrthxkijbeqcxhphysvur","itvwfelxfontyqvkohyznrmuchub","fwiwobucdnyowketvjlctzuvhjrt","awtohiebhyqhrxhhdvgaepzbnqvm","mbybkmixhyjjbwbavunjmvbzvbwr","ywbjpllitgeoiedmzwcwccpyaexa","pgwxhzqtmsrdkhyykewyrvubnhxi","iricritvvaandssoveatwynxxjdf","zexedfdrhzwkmuakghdbsrelsaib","ypppiefofbqsrzooihpymwgyfnmr","lknqszsnythaneoxxghxvypsxilh","rocxqunjycflkjqtkwpjbsjfbggd","qmtibvhtpucqyjbisrbfosopmaxo","nrmvwczztyelqljnwkdhxzmlwoop","vosmaimocjxcoxgnooqdeqqeqtek","exssazvezxaquyebuthdegrgrvii","yzrbfnwlqhtbrrgqoxjouexyprjr","hpnvxqktoxjerhugvzjqcvxjzfhc","ifapansscavkwfkokkdldojgcmnj","gmmjyzejicarabpbeuuivphxxkwa","mtgnqosivkjtzmfxmzjznkqilvsg","aeroymcmneuiamudaytftpncqapd","ovwebudjwveioynafnzrsxrltmmi","litldiekwibkzavsfyxyoajdhsna","wkkpzxwlcztrnjynldhmiqnvvgrz","szuddaainaeeswvywbpbvtgayvnk","kkxgomfmfrmbcoshmehgyaymecbu","dimhznnbwsdegmdqheqnnzfxwfqi","xqvqfazpiuiqrdphcqevzfgsmzau","eamqlmybygnexahzobidfplgsjsy","pytxsrvzvhxaxmuvcrhryhsnzfhb","wegvdhnxrvxjoiskmfnloysylzvm","xezvuaaoyzfmfjknzgxkowgjlubv","pafqzizotmxntddbjhnifrghtxhw","lxzemmfukbuocsvyzfnoankejjmr","rpnbgwwadzyfwfimovawduziierw","rozddodsbmivesuklybbbgintnxo","izrokmqrgseubhontrhwokyahmii","ojvtaxsrsdpidkmplulejmzcxznz","diwphyhtochmwhvujsdofymptnvp","dildbhtgjvvtpgmglbpptvksasmo","rmoyluuhyfabzpgbnpykyadasuya","ojktkrlnxvwzxtfuvayosuiygzzs","ugbehmgolwsbtvslnjgvkrylinvv","mcoemwoobcrwuovxwqgxfbmuzzne","aowysnfhbxnolhvjkdqbpzbthxyc","mgejpsrgnzodvercdtfuedoueotc","fyiatfuproopflfpukzarmjmqxfl","zwoycnuxpwnnvsccdorfvprlnyuy","ckiimfytdfbmhfsfpfkvxgyxzmmd","kytbhtnjakkulwagkqquomvbomhy","dxttdxwomkzczqxuaizxxhfkembi","fvkcspgbgwkyqeamzrlyblbghogs","wcpzxrkyvkcpfykarutslbdpocxs","enregkvvebcgbmxlhfggewomqywa","iyfrzsiybadwqpwjzcsxdfkhhrkv","wfyurkkthgejhzawkbjxeskolxjg","xyraghpnueveupxyshlpqoebehiy","gbheihzzrjsarzjbymxlpjivbsko","pzyguhgpkvwxbuuzwmahtomukoks","tsbagsgodcjjfosiaptjwcqaagos","ljgaotljyjgnwshsafaijzfdmfcs" };
		findSubstring("aratdgpfsookqyxiptwjllwirwmfdmafdayignqadektejbvcaepnbyezmlcalkfnkovaeydkixqsalwaqmptmwsajwaxifktvitbgwlqvdiwphyhtochmwhvujsdofymptnvpzlnewjtfhcaxghjeqhzzzepgebvxpqoqebuckqhuuhtbqdfgmghlmwuqypppiefofbqsrzooihpymwgyfnmrlgkjxzaffftnjlfamvoucfurecpjpdcblomjqnovukidvpgikwepebgidxttdxwomkzczqxuaizxxhfkembinjsqglllijcwubytryptgrrfyypekqmxzeqirbvclxyhbxcuxuodlfilfaqqsepulfecjzgwzfdaehubbkeorocxqunjycflkjqtkwpjbsjfbggdqmtibvhtpucqyjbisrbfosopmaxogdryqmitkpmzlrrkatuvmyaaqosdqpryukxkwhfgzuiklzwnurkhpkjfbbirsbqnlpzkyfsxbcimeebyxmhmyruzsctlglytaxfyeyyfcgtgmxfkjowjfqjyveldplwricppcnwevsnkpuuaisjoluoiyzlnkjeulwlpliujahtrdntlhczsxncxonlyxrvkngabowkqffjiuctbhvweiybxmoxlisvvzxyptkiyprijwcndxjjhhmgvbeijwegvdhnxrvxjoiskmfnloysylzvmfexbifznmmmgjkpxujkgpzrfyjfjkbxpfwtpbscqgpwrbnovwadlautyfahqbehiccxdwctcrrvuekrbkuokojktkrlnxvwzxtfuvayosuiygzzstqfjzpfljszinvilqphopfejzpihqjamzfvbuamftloiiyvbncrekvolkytbhtnjakkulwagkqquomvbomhykvkuvdxdykoyvyuiwwqgmgdasydjnlhxitreyrjwbxwyxritnacahfcbdgksrupzpjfoaomdnjekamepngpwlsxqakjrgasvjyjlowpcftohhuwwaounisgiepbkpthbtrmipbmuwcdgxzczpxnxrthxkijbeqcxhphysvuryxzxzbwoalmtgvsqedsiuwhdlrcgmwzmuyjvbijetxzatsszvmjrjqvwhzeuvdirbumdcyhxvizqaspygyprrmoyluuhyfabzpgbnpykyadasuyavosmaimocjxcoxgnooqdeqqeqtekpflktfyvnllruiwigexwsnaydqcwljgaotljyjgnwshsafaijzfdmfcsvgogruifovqohxcdrjwroyazyfcmmgejpsrgnzodvercdtfuedoueotcvyqhgvsvnjeciuhfazheupabuovycrczptixoatdlziutpbtqjzlaamuojvtaxsrsdpidkmplulejmzcxznzbbupkrinqdgjgvrlhdcsznylcynbzcbadxppoaeedlplihwqmzkoojbqjouksvkvubmidtoiegtonqgbrrrfcsynisxanjxhkmrqfhylnszckigbbxgdqeqawpblyyukmlarvzcitelfmtgnqosivkjtzmfxmzjznkqilvsgzflnytcpjwzegkyfwfejgnivzadkvyswdflcyptilsmrdmybrckasuvrxzeszyrceeecuxmfsbxxnvyhalhuhcnedrzcsqfwulyqlnwdovcbsaksnrmvwczztyelqljnwkdhxzmlwooprzheqwzoyzotzuhsfqfbailzkzkgobxfaflsdlhdmxylrhdwykzavkchkmpannhpuskxdrcrocfhkkdkvemqrozddodsbmivesuklybbbgintnxorjgiafldvqxxcfujzptmnwnqfxdymcoemwoobcrwuovxwqgxfbmuzznezselvsrhoivrmoqgeldcdlakomfonuuomzahttqkdndpdvwihzkknmxbaeroymcmneuiamudaytftpncqapdmmhnqadomhcbmwkmlgrneksazicqitvwfelxfontyqvkohyznrmuchubpytxsrvzvhxaxmuvcrhryhsnzfhbmdedcacwrxxmeupejjzlcjeaqxprexssazvezxaquyebuthdegrgrviisybwxuozvleuiemfeqizmpeqxvzprjzljakguagrmmlwszdxqlyeacuyavnrfmeomqxjrfcfrqbjpfihsgltlitldiekwibkzavsfyxyoajdhsnaayvliqyoycyunbgobcggcfgqhqvpkirkjmytcwhcbiyojeelimtkracysypcigotuopynwaoeyeqfibnuwynwcnqcdsnljggxxemuhaafgskovaksyzqcnhfsbsdkalkyswuzzugfnrwiricritvvaandssoveatwynxxjdfywbjpllitgeoiedmzwcwccpyaexapafqzizotmxntddbjhnifrghtxhwdewtgblfjkwcyvrravvjeiujaasvyzrbfnwlqhtbrrgqoxjouexyprjrsdmscgtjvqxoxsprjvjzvunpzkqqebhyfvqjdjtzbspbkeuvcduxxhoytgoxkvvptnawxvxanmbzrvuvaouavkyprpobkmsfzucyqzzfoafhyzcaoyalizczorcafuiepkdhlcmberietmfhkhutgxuwqxzvthbktergieipxqvqfazpiuiqrdphcqevzfgsmzaudildbhtgjvvtpgmglbpptvksasmosmlxvwawfweprbkghwouzfjsawmcqyrilcggaieggkxzlhhvgvrfcbaczmhpnayyeggeqmkzwjyjrgezdwegzgkytrpgtpgxxmcoaopwynhrtmqzkwfjdrjylageqocncgdcusaughnbtfcfchqhbbhmcpssduhfaljxdjtlqhpmmrrqbkzcliqnxihcfpjhcsehdatwhkivbboennizwyovjwyonhvpccyfctbldlghpulckwdgusbfobtdlruntsuvmyiplowalkfvgibcaeiqgdvrupgnickwasnmjkouwvpegsgiwqbeuwxoofeyiquijhwutnorkfvqxezvuaaoyzfmfjknzgxkowgjlubvzwoycnuxpwnnvsccdorfvprlnyuyuvvuujswyovpkjdidhkjveoqvfbifyiatfuproopflfpukzarmjmqxfleivkgdkckgrbwhtbtytpkspdeyruxwhefcqlhcnsihvgookjodzyxodcpvyorisykimukboukjdbankosjppastpnufhcyhoivivxwphisiihvwzenregkvvebcgbmxlhfggewomqywatsbagsgodcjjfosiaptjwcqaagoseksafuanoibrmmdtavbcmxmizcjzizrokmqrgseubhontrhwokyahmiiqthyvbpfnfwvycrzjhmeyvaogboppzyguhgpkvwxbuuzwmahtomukoksrbhhafnwptozpkzshttdhtndhzztpjlhkvomadlrwzrnlsfsnayxtladmbybkmixhyjjbwbavunjmvbzvbwrmywyzwcmikjplszmrammwcvizzjwagpngnngkpsscbinvjbmjqbfsyptxyraghpnueveupxyshlpqoebehiyfxtfxlfeswtoaqtwhsuzzhqrwuscbabjxuqwfxaztvotnjqubmtcuktsgnuknxvmulkbilbbirwwaoqdbmhxycrgpnqellshycigpjjycgwcumhxaowysnfhbxnolhvjkdqbpzbthxycmfbmwynonsyqpleatbmfhcgydkrlhpnvxqktoxjerhugvzjqcvxjzfhcpbnzqcupteijdunudkdyjmqnjnxkvgmkhcjaegpzmalquakxknyvbojmeiwzollynvytdpvrpghlgulthjolzxxdfwewhquwnupslmjbsroblzuuikhkkfnrbunkmjgzfxrrkcuctifgibdqmkcwrsnumdeyokzukqlushyopgwxhzqtmsrdkhyykewyrvubnhxiovwebudjwveioynafnzrsxrltmmitjqkgooiltthpzrdzefeuexocpzxbnhwyageowozqjihjzmigrpaymqcdpzgcidailgxkvyaejjpivaqmpskdimhznnbwsdegmdqheqnnzfxwfqiwivbthksxawvsbbynhowlgmahrzdypouajvtsilpihkajobwvrviyhihyjnwbbsbmpuexhufpgiaujyratzachkctzauasvmkrsjaoprxzrrislklknqszsnythaneoxxghxvypsxilhawtohiebhyqhrxhhdvgaepzbnqvmzgtbfppoxvrfuhongwujtblxqmygdtsecofjdxxasqhoxwcfuyqnbbnuplashuyjiesnbrqvhzkgxmlrmbhoeuithiooeoznstcvmsttsdbrrojdrsrvmbrtlhkqvlfqfhnrcgnulqlcfwiwobucdnyowketvjlctzuvhjrtzexedfdrhzwkmuakghdbsrelsaibjzukeuphzuaityuhuvtaeyewpiihkqjtsfdybufbqhlliiucdndjmhfdrpnbgwwadzyfwfimovawduziierwlxzemmfukbuocsvyzfnoankejjmrnepadpepdjkomgepbzpageogtzkdizwydmyiddxgojubqystzhtfmiofhykrzhpevomytkehvbknbcgdmakyiyfrzsiybadwqpwjzcsxdfkhhrkvtuvbtdssvcqwcvuslqdmsyjydufmnrigldjggdadftzkotezlimeixeltjxgahonlxwtcwxkpyuguaffktlsrpdmydtakjqxjmtliqxaqrgkunqejbxctcorhjustkrewkpgcngtgodcevhpzgrskhlsrfmmrdqpqhwswelfvrhzoqonyhhjotbhaptusljivfbrmoyhhigwywlxdtirojzoyuisiuddbgwnuxwefccdapcdkkxyvyptszoctrfvxektbhzilblororbyqcworpjqflmwtjvztpacqkqsvellvommqiajzlafxodqxbpqsrviblaypnkmeyyugbehmgolwsbtvslnjgvkrylinvvrvvmbwsilazwwraroscbejyqcwblkygdtbrualfnleljxlclgfokqmaslefxclawpssrdzerdrccffplkdxaszuddaainaeeswvywbpbvtgayvnkbkmtlhwrjyzyyddtbatzcidxbjzcgmmjyzejicarabpbeuuivphxxkwavvcejrnhqusawvrxwiyddulyjuxifvkcspgbgwkyqeamzrlyblbghogsifapansscavkwfkokkdldojgcmnjavclbeabrswvvrhtzrildlwgbindwcpzxrkyvkcpfykarutslbdpocxskkxgomfmfrmbcoshmehgyaymecbueamqlmybygnexahzobidfplgsjsynvstvhlitkktszzpzirqjbvptgxlrplhkfahmoqhaadszcjblctweonxwkkpzxwlcztrnjynldhmiqnvvgrzwfyurkkthgejhzawkbjxeskolxjggbheihzzrjsarzjbymxlpjivbskostuaudeckfedowdivplwbihqtpnxixlcricllgqymubcsfmowxkzirrbieaqcmstuwgffwdrshvlokbkjnjtgaxogxhijbbfyildgqwbzrondpznckiimfytdfbmhfsfpfkvxgyxzmmddosfyaplgqelvhzemtjbatzybxxbmlgpzyxyaoliertcytgnosoplppppmqbzwszwpzygmhkdcmdxtqmlhbywqpnefqddjebadagpjtulhyjaovnxyowodjulaxolcsnhsuzbptowtxziuohscdiinctpcjagbnnvjoyaknxdkynfmvzryiznmscodewfumafazgmodsydhfpcfgdpfsdzxudbqkvcmbdnjrbmjarrhgvonafut", words);
	}

private:
	/*vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.empty())return result;

		auto allExt = findall(s, words[0]);
		if (words.size() == 1)return allExt;

		int len = words[0].size();
		multiset<string> set;
		for (size_t i = 0; i < allExt.size(); i++)
		{
			set.clear();
			for (size_t j = 1; j < words.size(); j++)
			{
				set.insert(words[j]);
			}
			int pos = allExt[i];
			pos += len;
			while (!set.empty() && pos + len - 1< s.size())
			{
				string target = s.substr(pos, len);
				if (set.find(target) != set.end())
				{
					set.erase(target);
					pos += len;
				}
				else
				{
					break;
				}
			}
			pos = allExt[i];
			while (!set.empty() && pos - len >= 0)
			{
				string target = s.substr(pos - len, len);
				if (set.find(target) != set.end())
				{
					set.erase(target);
					pos -= len;
				}
				else
				{
					break;
				}
			}

			if (set.empty())
			{
				result.push_back(pos);
			}
		}
		return result;
	}*/

	vector<int> findall(string &s, string &p)
	{
		vector<int> result;
		size_t pos = s.find(p, 0);
		while (pos != string::npos)
		{
			result.push_back(pos);
			pos = s.find(p, pos + 1);
		}
		return result;
	}

	/*vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.empty())return result;
		unordered_multiset<string> set;
		int len = words[0].size();
		for (size_t i = 0; i < s.size(); i++)
		{
			set.clear();
			for (size_t j = 0; j < words.size(); j++)
			{
				set.insert(words[j]);
			}

			int pos = i, k = i;
			while (!set.empty() && k <= s.size() - len)
			{
				string target = s.substr(k, len);
				auto it = set.find(target);
				if (it != set.end())
				{
					set.erase(it);
					k += len;
				}
				else
				{
					i = k;
					break;
				}
			}
			if (set.empty()) {
				result.push_back(pos);
			}
		}
		return result;
	}*/

	/*"lingmindraboofooowingdingbarrwingmonkeypoundcake"
		["fooo", "barr", "wing", "ding", "wing"]
		"wordgoodgoodgoodbestword"
["word","good","best","word"]
"aaaaaa"
["aaa","aaa"]
		*/
	//1388 ms	13.8 MB
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.empty())return result;
		unordered_map<string, int> counts, backup;
		map<int, string> indexes;

		StartTiming();

		int lastIndexOfMin = s.size() - 1;
		for (size_t i = 0; i < words.size(); i++)
		{
			auto it = counts.find(words[i]);
			if (it != counts.end()) {
				it->second++;
			}
			else
			{
				counts.insert(make_pair(words[i], 1));
				auto v = findall(s, words[i]);
				if (v.empty())return result;
				if (words.size() == 1)return v;
				for (size_t j = 0; j < v.size(); j++)
					indexes.insert(make_pair(v[j], words[i]));
				lastIndexOfMin = min(lastIndexOfMin, (int)v[v.size() - 1]);
			}
		}

		PrintTiming();

		backup = counts;

		StartTiming();

		int len = words[0].size();
		for (auto it = indexes.begin();it->first <= lastIndexOfMin && it != indexes.end(); it++)
		{
			counts[it->second]--;
			auto it2 = next(it, 1);
			int formerIdx = it->first;
			while (it2 != indexes.end())
			{
				if (it2->first - formerIdx < len)
					it2++;
				else if (it2->first - formerIdx > len || counts[it2->second] <= 0)
					break;
				else if (it2->first - formerIdx == len) {
					counts[it2->second]--;

					bool isFound = true;
					for (auto t = counts.begin(); t != counts.end(); t++) {
						if (t->second > 0) {
							isFound = false;
							break;
						}
					}
					if (isFound) {
						result.push_back(it->first);
						break;
					}

					formerIdx = it2->first;
					it2++;
				}
			}
			counts = backup;
		}

		PrintTiming();

		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}