pipeline {
    agent any // Виконувати на будь-якому доступному вузлі

    tools {
        // Вказуємо Jenkins, що нам потрібен MSBuild, який ми налаштували в Manage Jenkins -> Tools
        msbuild 'MSBuild-VS2022' 
    }

    stages {
        stage('Checkout') {
            steps {
                // Завантажуємо код з репозиторію, який налаштований у самому завданні Jenkins
                checkout scm
            }
        }
        stage('Build') {
            steps {
                // Виконуємо команду збірки для конфігурації Debug.
                // bat - це команда для виконання у Windows Command Prompt.
                // "${msbuild}" - це змінна, яку Jenkins автоматично створює завдяки секції 'tools'.
                // Вона містить повний шлях до MSBuild.exe
                bat "\"${msbuild}\" test_repos.sln /p:Configuration=Debug /p:Platform=x64"
            }
        }
        stage('Test') {
            steps {
                // Запускаємо наш скомпільований .exe файл для виконання тестів.
                // Команда --gtest_output=xml:... створює звіт про тести у форматі XML.
                bat "x64\\Debug\\test_repos.exe --gtest_output=xml:test_report.xml"
            }
        }
    }
    post {
        always {
            // Цей крок виконується завжди після всіх стадій, навіть якщо вони провалилися.
            // Він шукає файл test_report.xml і публікує його результати.
            junit 'test_report.xml'
        }
    }
}