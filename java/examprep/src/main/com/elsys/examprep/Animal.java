package main.com.elsys.examprep;

public class Animal {
    private String name;
    private Kind kind;
    private Type type;
    private Boolean poolRequired;
    private Integer monthlyCost;

    public Animal(String name, Kind kind, Type type, Boolean poolRequired, Integer monthlyCost) {
        this.name = name;
        this.kind = kind;
        this.type = type;
        this.poolRequired = poolRequired;
        this.monthlyCost = monthlyCost;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Kind getKind() {
        return kind;
    }

    public void setKind(Kind kind) {
        this.kind = kind;
    }

    public Type getType() {
        return type;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public Boolean getPoolRequired() {
        return poolRequired;
    }

    public void setPoolRequired(Boolean poolRequired) {
        this.poolRequired = poolRequired;
    }

    public Integer getMonthlyCost() {
        return monthlyCost;
    }

    public void setMonthlyCost(Integer monthlyCost) {
        this.monthlyCost = monthlyCost;
    }
}
