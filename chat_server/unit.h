#ifndef UNIT_H
#define UNIT_H

typedef enum {
    ConnectedHost = 0x01,
    DisConnectedHost,

    LoginSuccess,       // 登录成功
    LoginPasswdError,   // 密码错误

    OnLine,
    OffLine,

    RegisterOk,
    RegisterFailed,

//    AddFriendOk,
//    AddFriendFailed,
} E_STATUS;
#endif // UNIT_H
