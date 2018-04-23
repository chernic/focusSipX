window.onload=function(){
    State2Init();
    gDomain=""
}
function State2Init(){
    $('#login_result').text("");
}
function State2InitedAndLogin(){
    $('#login_result').text("重复初始化");
}
// 状态:初始化中
function State2Initing(){
    $('#login_result').text("初始化中...");
}
// 状态:初始化成功
function State2Inited(){
    $('#login_result').text("初始化成功");
}
// 状态:登录成功
function State2Logined(){
    $('#login_result').text("登录成功");
}
// 状态:登录失败
function State2LoginFailed(){
    $('#login_result').text("登录失败");
}
// 状态:拨号成功
function State2Dialed(){
    $('#dial_result').text("拨号成功");
}
// 状态:拨号失败
function State2DialFailed(){
    $('#dial_result').text("拨号失败");
}

// 测试
// FocusSip 1 check_if_exited
function check_if_exited(){
    console.log("check_if_exited<<<<<<<");
    var o = new ActiveXObject("FocusSipAtl.FocusSip.1");
    if(o){
      alert("FocusSipAtl.FocusSip.1 存在 \FocusSipAtl.ocx 已成功加载");
    }
    else{
      alert("FocusSipAtl.FocusSip.1 不存在 \FocusSipAtl.ocx 加载失败");
    }
    
    console.log("focusua_aboutbox<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.focusua_aboutbox();
      // alert("RetVal:(focusua_aboutbox) " + retVal);
    }
    catch (e){ 
      alert( "FocusSip 1 focusua_aboutbox error: " + e.message); 
    }
    
    State2Init();
}
// FocusSip 11 focusua_init
function focusua_init(){
    State2Initing();
    console.log("focusua_init<<<<<<<");
    try{ 
      var retVal = document.all.FocusSip.focusua_init();
      if(retVal==0)
        State2Inited();
      if(retVal==1)
        State2InitedAndLogin();
      // alert("RetVal:(focusua_init) " + retVal);
    }
    catch (e){ 
      alert( "FocusSip 11 focusua_init error: " + e.message); 
    }
}
// FocusSip 13
function focusua_acc_add(){
    console.log("focusua_acc_add<<<<<<<");
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
    var pAcc_Index;
    try{
        var retVal = document.all.FocusSip.focusua_acc_add(UserID, Domain, Password, "");
        if(retVal==0)
        {
          State2Logined();
          gDomain = Domain;
        }
        if(retVal==-1)
        {
          State2LoginFailed();
        }
        // alert("RetVal:(focusua_acc_add) " + retVal);
    }
    catch (e){
        alert("FocusSip 13 focusua_acc_add error: " + e.message); 
    }
}
// FocusSip 14 focusua_account_add
function focusua_account_add(){
    console.log("focusua_account_add<<<<<<<");
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

    //{
    // account.splice(0,account.length);
    // account.push( _00accountId);
    // account.push( _01label);
    // account.push( _02server);
    // account.push( _03proxy);
    // account.push( _04username);
    // account.push( _05domain);
    // account.push( _06port);
    // account.push( _07authID);
    // account.push( _08password);
    // account.push( _09rememberPassword);
    // account.push( _10displayName);
    // account.push( _11voicemailNumber);
    // account.push( _12srtp);
    // account.push( _13transport);
    // account.push( _14publicAddr);
    // account.push( _15publish);
    // account.push( _16ice);
    // account.push( _17allowRewrite);
    // account.push( _18disableSessionTimer);
    // console.log("account.length = " + account.length);
    // var i, max = account.length;
    // for (i = 0; i < max; i++){
        // console.log("account[" + i + "] = " + account[i]);
    // }
    //}
    var pAcc_Index;
    try{
        var retVal = document.all.FocusSip.focusua_account_add(
        _00accountId, 
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
        pAcc_Index);
        if(retVal==0)
        {
          State2Logined();
          gDomain = Domain;
          // alert("RetVal:(focusua_account_add) " + retVal);
        }
        if(retVal==-1)
        {
          State2LoginFailed();
        }
    }
    catch (e){
        alert("FocusSip 14 focusua_account_add error: " + e.message); 
    }
}
var account = new Array();
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
// FocusSip 14 focusua_account_add
function focusua_make_call(){
    // var dial_text = document.getElementById("dial_text");
    var Number = $("#dial_text").val();
    var Domain = $("#Domain").val();
    if(Number==""){
      alert("请输入对方号码 (DialedNumber)");
      return;
    }
    if(Domain==""){
      if(gDomain==""){
        alert("请输入服务器域名(Domain)");
        return;
      }else{
        Domain = gDomain;
      }
    }

    var uri         = document.getElementById("_21number") ? document.getElementById("_21number") : (Number + "@" + Domain);
    var radio       = document.getElementById("hasVideo");
    var selectvalue = null;   //  selectvalue为radio中选中的值
    var hasVideo    = radio.checked?1:0;

    try{
      var retVal = document.all.FocusSip.focusua_make_call(
      uri,
      hasVideo);
      // alert("RetVal:(focusua_make_call) " + retVal); 
    }
    catch (e){
      alert( "focusua_make_call error: " + e.message); 
    }
}
var gDomain="";
// FocusSip 16 focusua_call_make_call
function focusua_call_make_call(){
    // var dial_text = document.getElementById("dial_text");
    var Number = $("#dial_text").val();
    var Domain = $("#Domain").val();

    if(Number=="")
    {
      alert("请输入对方号码 (DialedNumber)");
      return;
    }
    if(Domain=="")
    {
      if(gDomain=="")
      {
        alert("请输入服务器域名(Domain)");
        return;
      }else{
        Domain = gDomain;
      }
    }

    var CallInfo_numb = document.getElementById("_22numb") ? document.getElementById("_21callId")     : Number;
    var CallInfo_uri  = document.getElementById("_23number") ? document.getElementById("_21callId") : (Number + "@" + Domain);
    var CallInfo_para = document.getElementById("_24numberParameters") ? document.getElementById("_21callId"): "";
    var CallInfo_name = document.getElementById("_25name") ? document.getElementById("_21callId")     : Number;
    var CallInfo_callid = -1;

    console.log("CallInfo_numb = " + CallInfo_numb);
    console.log("CallInfo_uri  = " + CallInfo_uri);
    console.log("CallInfo_para = " + CallInfo_para);
    console.log("CallInfo_name = " + CallInfo_name);
    var radio=document.getElementById("hasVideo");
    var selectvalue=null;   //  selectvalue为radio中选中的值
    var _hasVideo = radio.checked?1:0;

   try{
      var retVal = document.all.FocusSip.focusua_call_make_call(
      CallInfo_uri,
      CallInfo_para,
      CallInfo_name,
      CallInfo_callid,
      _hasVideo);
      // alert("RetVal:(focusua_call_make_call) "  + retVal); 
    }
    catch (e){
      alert( "focus_acc_add error: " + e.message); 
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
///////////////////////// 华丽的分割线 ///////////////////////////}