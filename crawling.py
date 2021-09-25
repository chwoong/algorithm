from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
import time
import clipboard
import argparse


def parse():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--id', type=str, default=0, help='baekjoon id')
    parser.add_argument('-p', '--pw', type=str, default=0, help='baekjoon password')
    args = parser.parse_args()
    return args


if __name__ == '__main__':
    args = parse()
    select_lan = 1003
    # 본인 아이디 c++, 맞았습니다 로 check하고 계산
    # URL = 'https://www.acmicpc.net/status?problem_id=&user_id=' + str(args.id) + '&language_id=1001&result_id=4'
    URL = 'https://www.acmicpc.net/status?user_id=' + str(args.id) + '&language_id=1003&result_id=4'
    language = ['.cpp', '.java', '.py', '.c']
    driver = webdriver.Chrome("C:\selenium\chromedriver.exe")
    driver.implicitly_wait(100)
    driver.get(url=URL)
    print(driver.current_url)
    driver.find_element_by_xpath('/html/body/div[2]/div[1]/div[1]/div/ul/li[3]/a').click()

    driver.find_element_by_name('login_user_id').send_keys(args.id)
    driver.find_element_by_name('login_password').send_keys(args.pw)
    # driver.find_element_by_name('auto_login').click()
    driver.find_element_by_xpath('//*[@id="submit_button"]').click()
    # wait until login(time for capcha)
    driver.implicitly_wait(100)
    while True:
        table = driver.find_elements_by_xpath('//*[@id="status-table"]/tbody')
        driver.implicitly_wait(1000)
        # for row in table:
        # row.text = '24691174 chw0501 2162 맞았습니다!! 2160 40 C++17 / 수정 1648 8달 전'
        for t in table:
            lines = t.text.split('\n')
            break
        for line in lines:
            val = line.split(' ')
            # print(val[0]) # 채점 번호
            print(val[2]) # 문제 번호

            driver.find_element_by_xpath('//*[@id="solution-' + str(val[0]) + '"]/td[7]/a[1]').click()
            driver.implicitly_wait(10)
            # try:
            #     element = driver.find_element_by_xpath('/html/body/div[2]/div[2]/div[3]/div[5]/div/button')
            #     element.click()
            # except:
            #     driver.find_element_by_xpath('/html/body/div[2]/div[2]/div[3]/div[7]/div/button').click()
            driver.find_element_by_css_selector('body>div.wrapper>div.container.content>div.row>div.col-md-3>div>button').click()
            driver.implicitly_wait(10)
            driver.back()
            result = clipboard.paste()
            with open('./' + str((int(val[2])//1000)*1000) + '/' + val[2] + language[select_lan - 1001], 'w') as f:
                f.write(result)
            with open('./' + str((int(val[2])//1000)*1000) + '/' + val[2] + language[select_lan - 1001], 'r') as f:
                lines = f.readlines()
                result = ''
                for ind, line in enumerate(lines):
                    if ind % 2 == 0:
                        result += line
            with open('./' + str((int(val[2])//1000)*1000) + '/' + val[2] + language[select_lan - 1001], 'w') as f:
                f.write(result)
        try:
            driver.find_element_by_xpath('//*[@id="next_page"]').click()
            driver.implicitly_wait(10)
        except:
            break

