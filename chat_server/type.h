#ifndef TYPE_H
#define TYPE_H

typedef enum {
    Text,           // 普通文字消息
    Audio,          // 语音消息
    Picture,        // 图片消息
    Files,          // 文件传输
    Notice          // 通知
} MessageType;

typedef enum {
    NewFriend,           // 新朋友
    NewMember,           // 群组新成员
    ExitGroup,           // 群员退群
} NoticeType;

typedef enum {
    Unknow,
    Register            = 0x10,     // 用户注册
    Login,                          // 用户登录
    Logout,                         // 用户注销
    LoginRepeat,                    // 重复登录
    UserNotExist,                   // 用户不存在

    UserOnLine          = 0x15,     // 用户上线通知
    UserOffLine,                    // 用户下线通知
    UpdateHeadPic,                  // 用户更新头像

    AddFriend           = 0x20,     // 添加好友
    AddGroup,                       // 添加群组

    AddFriendRequist,               // 添加好友确认通知
    AddGroupRequist,                // 添加群组确认通知

    CreateGroup         = 0x25,     // 创建群组

    GetMyFriends        = 0x30,     // 上线获取我的好友的状态
    GetMyGroups,                    // 获取我的群组信息
    GetGroupMembers,                // 获取群组成员

    RefreshFriends      = 0x35,     // 刷新好友状态
    RefreshGroups,                  // 刷新群组成员状态

    SendMsg             = 0x40,     // 发送消息
    SendGroupMsg,                   // 发送群组消息
    SendFile,                       // 发送文件
    SendPicture,                    // 发送图片
    SendFace,                       // 发送表情

    ChangePasswd        = 0x50,     // 修改密码

    DeleteFriend        = 0x55,     // 删除好友
    DeleteGroup,                    // 退出群组

    SendFileOk          = 0x60,     // 文件发送完成状态

    GetFile             = 0x65,     // 获取文件（到服务器下载文件）
    GetPicture,                     // 图片下载

    MsgReceived         = 0x70,     //服务器收到了该条消息，向用户返回确认信息

    FindFriend          = 0x75,     //查找好友或者群

    GetOfflineMsg       = 0x80   ,   //获取离线消息
    SendFileHead
} E_MSG_TYPE;

typedef enum {
    ConnectedHost = 0x01,
    DisConnectedHost,

    LoginSuccess,       // 登录成功
    LoginPasswdError,   // 密码错误

    OnLine,
    OffLine,

    RegisterOk,
    RegisterFailed,

    AddFriendOk,
    AddFriendFailed,
} E_STATUS;
#endif // TYPE_H
