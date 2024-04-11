import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls.Material 2.15
import ChatClient 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "Клиент чата 2"

    ColumnLayout {
        TextField {
            id: messageInput
            placeholderText: "Введите сообщение..."
            Layout.fillWidth: true
            onAccepted: {
                if (messageInput.text.trim() !== "") {
                    client.sendMessage(messageInput.text)
                    messageInput.text = ""
                }
            }
        }

        Button {
            text: "Отправить"
            onClicked: {
                if (messageInput.text.trim() !== "") {
                    client.sendMessage(messageInput.text)
                    messageInput.text = ""
                }
            }
        }

        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout {
                id: messageContainer
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
    Connections {
        target: client
        onMessageReceived: {
            var messageLabel = Qt.createQmlObject('import QtQuick 2.15; Text { text: message; wrapMode: Text.Wrap }', messageContainer)
            messageLabel.text = "<b>Server:</b> " + message // Assign the 'message' value to the 'text' property of the 'Text' element
            messageLabel.color = "red" // Set the text color of the message to red
            messageLabel.font.bold = true // Make the message text bold
            messageContainer.children.push(messageLabel)
        }
    }
    Client {
        id: client
    }
}
