window.onload=function(){
    State2Init();
    gDomain=""
}
function State2Init(){
    $('#login_result').text("");
}

function State2Login(){
    $('#login_result').text("初始化成功");
}
function State2InitedAndLogin(){
    $('#login_result').text("失败,重复初始化等");
}
function State2Logout(){
    $('#login_result').text("反初始化成功");
}
function State2FailedLogout(){
    $('#login_result').text("失败,重复反初始化等");
}

function State2Logined(){
    $('#login_result').text("登录成功");
}
function State2LoginFailed(){
    $('#login_result').text("登录失败");
}
function State2Dialed(){
    $('#dial_result').text("拨号成功");
}
function State2DialFailed(){
    $('#dial_result').text("拨号失败");
}

////////////////////////////////////////////////////
var account = new Array();
var gDomain="";
function update_account(){
    console.log("update_account<<<<<<<");
    account.splice(0,account.length);
    account.push( _00accountId);
    account.push( _01label);
    account.push( _02server);
    account.push( _03proxy);
    account.push( _04username);
    account.push( _05domain);
    account.push( _06port);
    account.push( _07authID);
    account.push( _08password);
    account.push( _09rememberPassword);
    account.push( _10displayName);
    account.push( _11voicemailNumber);
    account.push( _12srtp);
    account.push( _13transport);
    account.push( _14publicAddr);
    account.push( _15publish);
    account.push( _16ice);
    account.push( _17allowRewrite);
    account.push( _18disableSessionTimer);
    console.log("account.length = " + account.length);
    var i, max = account.length;
    for (i = 0; i < max; i++){
        console.log("account[" + i + "] = " + account[i]);
    }
}
////////////////////////////////////////////////////
//// 0000000-0000000-0000000
// 001 // (OK)
function check_if_exited(){
    console.log("check_if_exited<<<<<<<");
    var o = new ActiveXObject("FocusSipAtl.FocusSip.1");
    if(o){
      alert(" FocusSipAtl.FocusSip.1 存在 \n FocusSipAtl.ocx 已成功加载");
    }
    else{
      alert("FocusSipAtl.FocusSip.1 不存在 \FocusSipAtl.ocx 加载失败");
    }
    
    console.log("aboutbox<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.aboutbox();
      // alert("RetVal:(aboutbox) " + retVal);
    }
    catch (e){ 
      alert( "aboutbox error: " + e.message); 
    }
}
// 002 // (OK) pjsua
function app_construct(){
    console.log("aboutbox<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.aboutbox();
      // alert("RetVal:(aboutbox) " + retVal);
    }
    catch (e){ 
      alert( "aboutbox error: " + e.message); 
    }
    
    console.log("app_construct<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.app_construct();
      // alert("RetVal:app_construct() " + retVal); 
      if(retVal==0)
        State2Login();
      if(retVal==1)
        State2InitedAndLogin();
    }
    catch (e){ 
      alert( "app_construct error: " + e.message); 
    }
}
// 003 // (OK) pjsua
function app_destroy(){
    console.log("app_destroy<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.app_destroy();
      // alert("RetVal:app_destroy() " + retVal); 
      if(retVal==0){
        State2Logout();
      }else{
        State2FailedLogout();
      }
    }
    catch (e){ 
      alert( "app_destroy error: " + e.message); 
    }
}

// 007 // (OK) pjsua
function app_default_config(){
    console.log("app_default_config<<<<<<<");
    try{ var retVal = document.all.FocusSip.app_default_config(); 
        alert("RetVal:app_default_config() " + retVal); }
    catch (e){ alert( "app_default_config error: " + e.message);}
}
// 008 // (OK) pjsua
function app_test_config(){
    console.log("app_test_config<<<<<<<");
    try{ var retVal = document.all.FocusSip.app_test_config(); 
        alert("RetVal:app_test_config() " + retVal); }
    catch (e){ alert( "app_test_config error: " + e.message);}
}

////////////////////////////////////////////////////
//// 1111111-1111111-1111111
// 101
function acc_get_count(){
    console.log("acc_get_count<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.acc_get_count();
      // alert("RetVal:acc_get_count() " + retVal); 
      $('#acc_get_count_result').text(retVal);
    }
    catch (e){ 
      alert( "acc_get_count error: " + e.message); 
    }
}
// 102
function acc_get_info(){
    console.log("acc_get_info<<<<<<<");
    try{ 
      var acc_id = 1;
      var pInfo;// 不正确的变量类型
      var retVal = document.all.FocusSip.acc_get_info(acc_id, pInfo);

      alert("RetVal:acc_get_info() " + retVal); 
      $('#acc_get_count_result').text(retVal);
    }
    catch (e){ 
      alert( "acc_get_info error: " + e.message); 
    }
}
// 105
function acc_set_online_status(){
    console.log("acc_set_online_status<<<<<<<");
    try{ 
      var acc_id    = 1;
      var is_online = $("#online_status2set").val();
      var retVal    = document.all.FocusSip.acc_set_online_status(acc_id, is_online);
      alert("RetVal:acc_set_online_status() " + retVal); 
    }
    catch (e){ 
      alert( "acc_set_online_status error: " + e.message); 
    }
}
// 106
function acc_set_registration(){
    console.log("acc_set_registration<<<<<<<");
    try{ 
      var acc_id     = 1;
      var reg_active = $("#registration2set").val();
      var retVal     = document.all.FocusSip.acc_set_registration(acc_id, reg_active);
      alert("RetVal:acc_set_registration() " + retVal); 
    }
    catch (e){ 
      alert( "acc_set_registration error: " + e.message); 
    }
}
// 103
function acc_add_short(){
    console.log("acc_add_short<<<<<<<");
    try{ 
    // /* [in] */ VideoAgent_Acc_Config *pconfig, 
    // /* [out] */ int *pAcc_Index, 
      var pconfig     = 1;
      var pAcc_Index  = 1;
      var retVal      = document.all.FocusSip.acc_add_short(pconfig, pAcc_Index);
      alert("RetVal:acc_add_short() " + retVal); 
    }
    catch (e){ 
      alert( "acc_add_short error: " + e.message); 
    }
}
// 104
function acc_add(){
    console.log("acc_add<<<<<<<");
    var UserID   = $("#UserID").val();
    var Domain   = $("#Domain").val();
    var Password = $("#Password").val();

    if(UserID==""){
      alert("请输入用户帐号 (UserID)");
      return;
    }
    if(Domain==""){
      alert("请输入服务器域名(Domain)");
      return;
    }
    if(Password==""){
      alert("请输入服务器域名(Domain)");
      return;
    }

    var _00accountId  = $("#_00accountId").val()  ? $("#_00accountId").val()  : "1";
    var _01label      = $("#_01label").val()      ? $("#_01label").val()      : UserID;
    var _02server     = $("#_02server").val()     ? $("#_02server").val()     : Domain;
    var _03proxy      = $("#_03proxy").val()      ? $("#_03proxy").val()      : "";
    var _04username   = $("#_04username").val()   ? $("#_04username").val()   : UserID;
    var _05domain     = $("#_05domain").val()     ? $("#_05domain").val()     : Domain ;
    var _06port       = $("#_06port").val()       ? $("#_06port").val()       : "0";
    var _07authID     = $("#_07authID").val()     ? $("#_07authID").val()     : UserID;
    var _08password   = $("#_08password").val()   ? $("#_08password").val()   : Password;
    var _09rememberPassword   = $("#_09rememberPassword").val()   ? $("#_09rememberPassword").val()   : "1";
    var _10displayName        = $("#_10displayName").val()        ? $("#_10displayName").val()        : UserID;
    var _11voicemailNumber    = $("#_11voicemailNumber").val()    ? $("#_11voicemailNumber").val()    : "";
    var _12srtp               = $("#_12srtp").val()               ? $("#_12srtp").val()               : "";
    var _13transport          = $("#_13transport").val()          ? $("#_13transport").val()          : "";
    var _14publicAddr         = $("#_14publicAddr").val()         ? $("#_14publicAddr").val()         : "";
    var _15publish            = $("#_15publish").val()            ? $("#_15publish").val()            : "0";
    var _16ice                = $("#_16ice").val()                ? $("#_16ice").val()                : "0";
    var _17allowRewrite       = $("#_17allowRewrite").val()       ? $("#_17allowRewrite").val()       : "0";
    var _18disableSessionTimer= $("#_18disableSessionTimer").val()? $("#_18disableSessionTimer").val(): "0";

    var retVal = -1;
    try{
        var pAcc_Index = document.all.FocusSip.acc_add(
        //_00accountId, 
        _01label,
        _02server,
        _03proxy,
        _04username,
        _05domain,
        _06port,
        _07authID,
        _08password,
        _09rememberPassword,
        _10displayName,
        _11voicemailNumber,
        _12srtp,
        _13transport,
        _14publicAddr,
        _15publish,
        _16ice,
        _17allowRewrite,
        _18disableSessionTimer,
        retVal);

        $('#acc_id_return').text(pAcc_Index);
        $("#acc_id_2_del").val(pAcc_Index);

        console.log("Ret(acc_add) %s", pAcc_Index);
        
        if( pAcc_Index == -1 || pAcc_Index >= 20000)
        {
          State2LoginFailed();
        }else{
          State2Logined();
          gDomain = Domain;
        }
    }
    catch (e){
        alert( "acc_add error: " + e.message); 
    }
}
// 107
function acc_del(){
    console.log("acc_del<<<<<<<");

    var acc_index=  $("#acc_id_2_del").val();
    try{ 
      var retVal = document.all.FocusSip.acc_del(acc_index);
      $('#acc_del_return').text(retVal);
    }
    catch (e){ 
      alert( "acc_del error: " + e.message); 
    }
}


////////////////////////////////////////////////////
//// 3333333-3333333-3333333
// 201 最大支持呼叫数
function call_get_max_count(){
    console.log("call_get_max_count<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.call_get_max_count();
      alert("RetVal:call_get_max_count() " + retVal); 
    }
    catch (e){ 
      alert( "call_get_max_count error: " + e.message); 
    }
}
// 202 当前正在通话数量
function call_get_count(){
    console.log("call_get_count<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.call_get_count();
      alert("RetVal:call_get_count() " + retVal); 
    }
    catch (e){ 
      alert( "call_get_count error: " + e.message); 
    }
}
// 203 指定通话是否在进行
function call_is_active(){
    console.log("call_is_active<<<<<<<");
    try{ 
      var call_id = $("#call_make_call_id_show").val();;
      var retVal = document.all.FocusSip.call_is_active(call_id);

      console.log("Return(call_is_active)=" + retVal);
    }
    catch (e){ 
      alert( "call_is_active error: " + e.message); 
    }
}
// 204 指定通话时候含有媒体
function call_has_media(){
    console.log("call_has_media<<<<<<<");
    try{
      var call_id = $("#call_make_call_id_show").val();;
      var retVal = document.all.FocusSip.call_has_media(call_id);

      console.log("Return(call_has_media)=" + retVal);
    }
    catch (e){ 
      alert( "call_has_media error: " + e.message); 
    }
}
// 205
function call_get_info(){
    console.log("call_get_info<<<<<<<");
    try{ 
      var call_id = $("#call_make_call_id_show").val();;
      var pInfo;// 不正确的变量类型
      var retVal = document.all.FocusSip.call_get_info(call_id, pInfo);
      alert("RetVal:call_get_info() " + retVal); 
    }
    catch (e){ 
      alert( "call_get_info error: " + e.message); 
    }
}
//// 3333333-3333333-3333333
// 211
function call_make_call_short(){
    var Number = $("#dial_text").val();
    var Domain = $("#Domain").val();

    if(Number==""){
      alert("请输入对方号码 (DialedNumber)");
      return;
    }
    if(Domain==""){
      if(gDomain=="")
      {
        alert("请输入服务器域名(Domain)");
        return;
      }else{
        Domain = gDomain;
      }
    }

    var CallInfo_callId = document.getElementById("_21callId") ? document.getElementById("_21callId") : -1;
    var CallInfo_numb   = document.getElementById("_22numb")   ? document.getElementById("_22numb")   : Number;
    var CallInfo_number = document.getElementById("_23number") ? document.getElementById("_23number") : (Number + "@" + Domain);
    var CallInfo_numberParameters = "";
    var CallInfo_name   = document.getElementById("_25name")   ? document.getElementById("_25name")   : Number;

    // console.log("CallInfo_callId            =" + CallInfo_callId);
    // console.log("CallInfo_numb              =" + CallInfo_numb);
    // console.log("CallInfo_number            =" + CallInfo_number);
    // console.log("CallInfo_numberParameters  =" + CallInfo_numberParameters);
    // console.log("CallInfo_name              =" + CallInfo_name);

    var uri             = document.getElementById("_22numb") ? document.getElementById("_22numb") : (Number + "@" + Domain);
    console.log("uri              =" + uri);

    var radio=document.getElementById("hasVideo");
    var selectvalue=null;
    var _hasVideo = radio.checked?1:0;

   try{
      var retVal = document.all.FocusSip.call_make_call_short(
      uri,
      _hasVideo);
      $('#call_make_call_id').text(retVal);
      $("#call_make_call_id_show").val(retVal);
      console.log("Return(call_make_call)=" + retVal);
    }
    catch (e){
      alert( "call_make_call_short error: " + e.message); 
    }
}
// 212
function call_make_call(){
    // var dial_text = document.getElementById("dial_text");
    var Number = $("#dial_text").val();
    var Domain = $("#Domain").val();

    if(Number==""){
      alert("请输入对方号码 (DialedNumber)");
      return;
    }
    if(Domain==""){
      if(gDomain=="")
      {
        alert("请输入服务器域名(Domain)");
        return;
      }else{
        Domain = gDomain;
      }
    }

    var CallInfo_callId = document.getElementById("_21callId") ? document.getElementById("_21callId") : -1;
    var CallInfo_numb   = document.getElementById("_22numb")   ? document.getElementById("_22numb")   : Number;
    var CallInfo_number = document.getElementById("_23number") ? document.getElementById("_23number") : (Number + "@" + Domain);
    // var CallInfo_numberParameters = document.getElementById("_24numberParameters") ? document.getElementById("_21callId"): "";
    var CallInfo_numberParameters = "";
    var CallInfo_name = document.getElementById("_25name")     ? document.getElementById("_25name")   : Number;

    console.log("CallInfo_callId            =" + CallInfo_callId);
    console.log("CallInfo_numb              =" + CallInfo_numb);
    console.log("CallInfo_number            =" + CallInfo_number);
    console.log("CallInfo_numberParameters  =" + CallInfo_numberParameters);
    console.log("CallInfo_name              =" + CallInfo_name);

    var uri         = document.getElementById("_21number") ? document.getElementById("_21number") : (Number + "@" + Domain);
    var radio=document.getElementById("hasVideo");
    var selectvalue=null;   //  selectvalue为radio中选中的值
    var _hasVideo = radio.checked?1:0;

   try{
      var retVal = document.all.FocusSip.call_make_call(
      CallInfo_callId,
      CallInfo_numb,
      CallInfo_number,
      CallInfo_numberParameters,
      CallInfo_name,
      _hasVideo);
      $('#call_make_call_id').text(retVal);
      $("#call_make_call_id_show").val(retVal);
      console.log("Return(call_make_call)=" + retVal);
    }
    catch (e){
      alert( "call_make_call error: " + e.message); 
    }
}
// 213
function call_answer(){
    console.log("call_answer<<<<<<<");
    try{ 
      var call_id     = $("#call_make_call_id_show").val();
      var status_code = $("#call_answer_status_code").val();
      
      var retVal = document.all.FocusSip.call_answer(call_id, status_code);

      console.log("Return(call_answer)=" + retVal);
    }
    catch (e){ 
      alert( "call_answer error: " + e.message); 
    }
}
// 214
function call_hangup(){
    console.log("call_hangup<<<<<<<");
    try{ 
      var call_id   = $("#call_make_call_id_show").val();
      var code      = 0;
      var reason    = "";
      
      var retVal = document.all.FocusSip.call_hangup(call_id, code, reason);
      console.log("Return(call_hangup)=" + retVal);
    }
    catch (e){ 
      alert( "call_hangup error: " + e.message); 
    }
}
// 215
function call_hangup_all(){
    console.log("call_hangup_all<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.call_hangup_all();
      console.log("Return(call_hangup_all)=" + retVal);
    }
    catch (e){ 
      alert( "call_hangup_all error: " + e.message); 
    }
}
// 216
function call_set_hold(){
    console.log("call_set_hold<<<<<<<");
    try{ 
        var call_id   = $("#call_make_call_id_show").val();
        var retVal = document.all.FocusSip.call_set_hold(call_id);
        console.log("Return(call_set_hold)=" + retVal);
    }
    catch (e){ 
        alert( "call_set_hold error: " + e.message); 
    }
}
// 217
function call_release_hold(){
    console.log("call_release_hold<<<<<<<");
    try{ 
        var call_id   = $("#call_make_call_id_show").val();
        var retVal = document.all.FocusSip.call_release_hold(call_id);
        console.log("Return(call_release_hold)=" + retVal);
    }
    catch (e){ 
        alert( "call_release_hold error: " + e.message); 
    }
}

////////////////////////////////////////////////////
//// 3333333-3333333-3333333
// 301 
function vid_win_set_overlay_mode(mode){
    console.log("vid_win_set_overlay_mode<<<<<<<");
   var VedioWinMode = document.getElementById("VedioWinMode") ? document.getElementById("VedioWinMode") : mode;
   try{
      console.log("vid_win_set_overlay_mode(VedioWinMode=%s)", VedioWinMode);
      var retVal = document.all.FocusSip.vid_win_set_overlay_mode(VedioWinMode);

      if(0!=retVal){
        alert("vid_win_set_overlay_mode : retVal= "+ retVal);
      }
    }
    catch (e){
      alert( "vid_win_set_overlay_mode error: " + e.message); 
    }
}
// 302
function vid_win_resize(){
   console.log("vid_win_resize<<<<<<<");
   var VedioWinMode = $("#VedioWinSize").val();
   
   console.log("vid_win_resize(%s)",VedioWinMode);
   try{
      var retVal = document.all.FocusSip.vid_win_resize(VedioWinMode);
      if(0!=retVal){
        alert("vid_win_resize : retVal= "+ retVal);
      }
    }
    catch (e){
      alert( "vid_win_resize error: " + e.message); 
    }
}

///////////////////////// 华丽的分割线 ///////////////////////////{
function type1(){console.log("type1<<<");
    var dial_text = document.getElementById("dial_text");
    var value ="";
    if(dial_text) 
        value = dial_text.value
    dial_text.setAttribute('value', value + "1");
}
function type2(){console.log("type2<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "2");
}
function type3(){console.log("type3<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "3");
}
function type4(){console.log("type4<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "4");
}
function type5(){console.log("type5<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "5");
}
function type6(){console.log("type6<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "6");
}
function type7(){console.log("type7<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "7");
}
function type8(){console.log("type8<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "8");
}
function type9(){console.log("type9<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "9");
}
function typestar(){console.log("typestar<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "*");
}
function type0(){console.log("type0<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "0");
}
function type3sharp(){console.log("type3sharp<<<");
    var dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + "#");
}
function my_delete(){console.log("my_delete<<<");
    dial_text = document.getElementById("dial_text");
    var str = dial_text.value;
    str = str.substr(0,str.length-1);
    dial_text.setAttribute('value', str );
}
function my_add(){console.log("my_add<<<");
    dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', dial_text.value + '+');
}
function my_clear(){console.log("my_clear<<<");
    dial_text = document.getElementById("dial_text");
    dial_text.setAttribute('value', "");
}