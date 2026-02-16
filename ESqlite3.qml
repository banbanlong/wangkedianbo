import QtQuick
import QtQuick.LocalStorage

Item {
    opacity: 0.0
    property var db
    function init(){
        db = LocalStorage.openDatabaseSync("Edoyun","1.0","记录程序运行时需要记录的数据，例如：账号、密码、设置等等",10000)
        try{
            db.transaction(function(tx){
                tx.executeSql('CREATE TABLE IF NOT EXISTS data(name TEXT, value TEXT)')
            })
        }catch(err){
            console.log("create database failed!:"+err)
        }
    }
    function read(key){
        var ret = ""
        if(!db)return ""
        db.transaction(function(tx){
            var result = tx.executeSql('select value from data where name=?',[key])
            if(result.rows.length>0){
                ret = result.rows.item(0).value
            }else{
                ret = ""
            }
        })
        return ret
    }
    function write(key, value){
        var ret = -1
        if(!db)return ret
        db.transaction(function(tx){
            var result = tx.executeSql('select value from data where name=?',[key])
            if(result.rows.length>0){
                tx.executeSql('delete from data where name=?',[key])
            }
            result = tx.executeSql('insert into data values(?,?)',[key, value])
            if(result.rowsAffected > 0){
                ret = 0
            }else{
                ret = -2
            }
        })
        return ret
    }
}
