<?php
mb_language('japanese');
mb_internal_encoding('UTF-8');

if ($json = file_get_contents('php://input'))
    $data = json_decode($json, true);
    /*　$data　の構成 */
    /* -name ... 問い合わせフォーム用(オプション)
       -fromAddress ... 送信元メールアドレス
       -atAddress ... 送信先メールアドレス
       -subject ... メール題名
       -message ... メール内容
    */

//入力必須欄の確認
if ($data['fromAddress']==null) exit('fromAddress is null');
else if($data['atAddress']==null) exit('atAddress is null');
else if($data['subject']==null) exit('subject is null');
else if($data['message']==null) exit('message is null');

$fromAddress = $data['fromAddress'];
$atAddress = $data['atAddress'];
$subject = $data['subject'];
$message = html_entity_decode($data['message']);
//if($data['name']!=null) $name = $data['name'];

$body = htmlspecialchars($message, ENT_QUOTES, "UTF-8");
$success = mb_send_mail($atAddress, $subject, $body, 'From: ' . $fromAddress);
if($success){
    echo "success";
}