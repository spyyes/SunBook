# Maven

> This is the quick reference for first-hand maven users.

编译test

```sh
mvn test
```

生成jar包，并忽略Test，因为Test跑不通

```sh
mvn package -DskipTests
```

查看项目依赖并下载的JAR包，一般目录在target/dependency，如需修改目录见下面的code

```sh
mvn dependency:copy-dependencies
```

针对test 生成jar包 ; 需要在pom.xml添加

```xml
      <plugin>
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-jar-plugin</artifactId>
        <version>3.0.2</version>
        <executions>
          <execution>
            <goals>
              <goal>test-jar</goal>
            </goals>
          </execution>
        </executions>
      </plugin>
```

修改dependency下载的位置，需要在pom.xml中添加

```xml
        <plugin>
          	<artifactId>maven-dependency-plugin</artifactId>
         	<configuration>
	            <excludeTransitive>false</excludeTransitive> 
	            <stripVersion>true</stripVersion>
	            <outputDirectory>./lib</outputDirectory>
            </configuration>         
        </plugin>
```

清空项目的缓存，以便重新编译

```sh
mvn clean
```

